#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define M 1000000007
#define pb push_back
#define ms(a,b) (((a%M)+(b%M))%M)
vector<ll> dp;
ll solve(int n, int k) {
	ll ans = 0;
	dp.assign(k, 0);
	dp[0] = 1;
	int u, v, w;
	for (u = 1; u <= (n - 1); ++u) {
		for (v = min(k - 1, u); v > 0; --v) {
			dp[v] = ms(dp[v], dp[v - 1]);
		}
	}
	return dp[k - 1];
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, k;
		sc = scanf("%d %d", &n, &k);
		if (k == n) {
			printf("1\n");
			continue;
		}
		if (k > n) {
			printf("0\n");
			continue;
		}
		ll res = solve(n, k);
		printf("%llu\n", res);
	}
	return 0;
}