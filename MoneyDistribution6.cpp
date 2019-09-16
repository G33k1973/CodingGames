#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define M 1000000007
#define pb push_back
#define ms(a,b) (((a%M)+(b%M))%M)
vector<vector<ll>> dp;
map<vector<int>, int> seen;
ll dfs(int n, int k, int cum) {
	if (k == 1) {
		return 1ULL;
	}
	int rem = n - cum;
	int cmax = rem - k + 1;
	ll ans = 0;
	for (int i = 1; i <= cmax; ++i) {
		ans = ms(ans, dfs(n, k - 1, cum + i));
	}
	return dp[n][k] = ans;
}
ll solve(int n, int k) {
	ll ans = 0;
	dp.assign(n + 1, vector<ll>(k + 1, 0));
	int u, v, w;
	for (u = 0; u <= n; ++u) {
		for (v = 0; v <= min(u, k); ++v) {
			if (v == 0 || u == v)dp[u][v] = 1;
			else dp[u][v] = ms(dp[u - 1][v - 1], dp[u - 1][v]);
		}
	}
	return dp[n - 1][k - 1];
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