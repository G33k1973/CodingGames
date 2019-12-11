// you can use includes, for example:
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
struct Order {
public:
	int val, ncount;
	vector<int> lcons;
	Order() {
		val = ncount = -1;
		lcons = vector<int>{};
	}
	Order(int x, int n, vector<int>& arr) :val(x), ncount(n) {
		this->lcons.assign(begin(arr), end(arr));
	}
	bool operator>(const struct Order& obj) const {
		if (ncount == obj.ncount)return lcons > obj.lcons;
		return ncount > obj.ncount;
	}
	bool operator<(const struct Order& obj) const {
		if (ncount == obj.ncount)return lcons < obj.lcons;
		return ncount < obj.ncount;
	}
	bool operator==(const struct Order& obj) const {
		return (ncount == obj.ncount && (lcons == obj.lcons));
	}
};
struct Functor {
	bool operator()(const struct Order& a, const struct Order& b) {
		return a > b;
	}
};
struct Functor2 {
	bool operator() (const struct Order& a, const struct Order& b) {
		return (a == b);
	}
} local;
int SlidingWindow(const std::vector<int>& arr, int n, int K, int x) {
	int l = 0, r = 0;
	int res = 0, cnt = 0;
	while (r < n) {
		if (arr[r] != x)++cnt;
		while (cnt > K) {
			if (arr[l] != x)--cnt;
			++l;
		}
		res = max(res, r - l + 1);
		++r;
	}
	return res;
}
int solution(vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	K = std::min(K, n);
	int res(0);
	unordered_set<int> h;
	int i(0);
	vector<Order> arr;
	for (auto& x : A) {
		if (h.count(x) == 0) {
			h.insert(x);
			//Value is "x"
			if (i)i = 0;
			int c(0);
			int tot(0);
			vector<int> temp;
			while (i < n) {
				if (A.at(i) == x) {
					++c;
				}
				else {
					temp.pb(c);
					tot += c;
				}
				++i;
			}
			if (c) {
				tot += c;
				temp.pc(c);
			}
			Order current(x, tot, temp);
			arr.pb(current);
		}
	}
	std::sort(begin(arr), end(arr), Functor());
	int m = static_cast<int>(arr.size());
	for (i = 0; i < m;++i) {
		if (i&&local(arr[i], arr[i - 1]))continue;
		if (i&&arr[i] < arr[i - 1])break;
		res = max(res, SlidingWindow(A, n, K, arr[i].val));
	}
	return res;
}

int main(int argc, char ** argv) {
	int K=1;
	vector<int> a{ 1,1,2,3,4,1,1,2,7,1 };
	if (argc == 2) {
		K = atoi(argv[1]);
		if (K < 0) {
			cout << "Invalid K = " << K << " prescribed by user: value must be non negative.";
			exit(1);
		}
	}
	cout << "Longest subarray is " << solution(a, K) << endl;
	return 0;
}