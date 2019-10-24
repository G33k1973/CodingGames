// you can use includes, for example:
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#define pb push_back
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(A.size());
	if (n < 3)return 0;
	set<int> peaks;
	int i = 1;
	while (i < n - 1) {
		if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
			peaks.insert(i);
		}
		++i;
	}
	n = (int)peaks.size();
	int res = 0;
	int m = n;
	while (1) {
		int i = *begin(peaks);
		int sub = 0;
		int k = m;
		int av = k;
		while (1) {
			++sub, --av;
			if (av == 0)break;
			auto it = peaks.lower_bound(i + k);
			if (it == end(peaks))break;
			i = *it;
		}
		if (sub < res)break;
		res = max(res, sub);
		--m;
		if (m == 0)break;
	}
	return res;
}