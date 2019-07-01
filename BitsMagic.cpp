#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
vector<int> px, sx;
int sum;
using ll = unsigned long long int;
#define N 60
ll DP[N + 1][N + 1];
void init() {
	memset(DP, 0, sizeof(DP));
	int i, j;
	for (i = 1; i <= N; ++i) {
		for (j = 0; j <= min(N, i); ++j) {
			if (i == j || j == 0)DP[i][j] = 1;
			else DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
		}
	}
	return;
}
#define PRINT
#undef PRINT
ll solve(ll x) {
	vector<int> arr;
	sum = 0;
	ll i = 0;
	bool st = 0;
	for (i = 1ULL << 63ULL; i > 0; i >>= 1) {
		if (x&i) {
			if (!st)st = !st;
			arr.pb(1);
			++sum;
		}
		else if (st == true)
			arr.pb(0);
	}
#if defined PRINT
	for (const auto& x : arr)cout << x << ' ';
	cout << '\n';
#endif
	int n = static_cast<int>(arr.size());
	if (sum == n)return 0;
	int l = n - 1;
	ll res = DP[l][sum];
	ll y = 1ULL << (l);
	for (ll j = y + 1; j < x; ++j) {
		int c = 0;
		ll z = j;
		while (z) {
			z &= z - 1;
			++c;
			if (c > sum)break;
		}
		if (c == sum)++res;
	}
	return res;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	init();
	while (q--) {
		ll x;
		int sc = scanf("%llu", &x);
		printf("%llu\n", solve(x));
	}
	return 0;
}