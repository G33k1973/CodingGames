// you can use includes, for example:
#include <algorithm>
#define BIG 1000000000
#define THRESHOLD 44710
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using ll = unsigned long long int;
ll GetSum(ll x) {
	if (x & 1)return (((x + 1) >> 1)*x);
	return ((x >> 1)*(x + 1));
}
ll solution(vector<bool> &P) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(P.size());
	ll res = 0;
	if (n == 0)return res;
	if (n == 1) {
		return (P[0] == 1) ? (1) : (0);
	}
	int i;
	while (n > 0) {
		int c = 0;
		for (i = 0; i < n; ++i) {
			if (P[i])++res, ++c;
			if (res > BIG)return BIG;
		}
		if (c == n) {
			if (n > THRESHOLD)return BIG;
			res += GetSum(n - 1);
			if (res > BIG)return BIG;
			break;
		}
		for (i = 0; i < n - 1; ++i) {
			if (P[i] || P[i + 1])P[i] = 1;
			else P[i] = 0;
		}
		--n;
	}
	return res;
}