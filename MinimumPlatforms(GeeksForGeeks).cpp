#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct platforms {
	int hs, ms, he, me;
	int ts, te;
	platforms() {}
	platforms(int a, int b) :hs(a), ms(b) {}
	platforms& Update(int a, int b) {
		this->he = a;
		this->me = b;
		ts = hs * 60 + ms;
		te = he * 60 + me;
		return *this;
	}
	bool operator<(const struct platforms& ob) const {
		return te < ob.te;
	}
};

struct Functor {
	bool operator()(const struct platforms& a, const struct platforms& b) {
		return a < b;
	}
};

void dfs(const std::vector<platforms>& a, int n, int i, vector<bool>& visited, int te) {
	if (i == n)return;
	if (visited[i] || a[i].ts < te)dfs(a, n, i + 1, visited, te);
	else {
		visited[i] = true;
		dfs(a, n, i + 1, visited, a[i].te);
	}
}

int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<int> arr(n, 0), dep(n, 0);
		char c[5];
		for (int i = 0; i < n; ++i) {
			sc = scanf("%s", c);
			int H = (c[0] - '0') * 10 + (c[1] - '0');
			int M = (c[2] - '0') * 10 + (c[3] - '0');
			arr[i] = 60 * H + M;
		}
		for (int i = 0; i < n; ++i) {
			sc = scanf("%s", c);
			int H = (c[0] - '0') * 10 + (c[1] - '0');
			int M = (c[2] - '0') * 10 + (c[3] - '0');
			dep[i] = H * 60 + M;
		}
		{
			int res = INT_MIN;
			vector<int> times(1500, 0);
			for (int i = 0; i < n; ++i) {
				times[arr[i]]++;
				times[dep[i] + 1]--;
			}
			for (int i = 1; i < 1500; ++i) {
				times[i] += times[i - 1];
				if (res < times[i])res = times[i];
			}
			printf("%d\n", res);
			continue;
		}
	}
	return 0;
}