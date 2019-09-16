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
	if (!seen.empty())seen.clear();
	dp.assign(n + 1, vector<ll>(k + 1, -1));
	return ans = dfs(n, k, 0);
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