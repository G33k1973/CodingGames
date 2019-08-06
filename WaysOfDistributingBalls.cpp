#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
ll dfs(int n, int i, int av, vector<vector<ll>>& dp, vector<ll>& sx, const std::vector<ll>& balls) {
	if (i == (n - 1)) {
		return 1;
	}
	if (dp[i][av] != -1)return dp[i][av];
	if (av < 0) {
		dp[i][av] = 0;
		return 0;
	}
	int possible = av - sx[i + 1];
	if (balls[i] == possible) {
		dp[i][av] = 1;
		return 1;
	}
	ll ans = 0;
	for (ll j = balls[i]; j <= possible; ++j) {
		ll sub = dfs(n, i + 1, av - j, dp, sx, balls);
		ans = ms(sub, ans);
	}
	return dp[i][av] = ans;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int m, n, p;
		sc = scanf("%d %d %d", &m, &n, &p);
		vector<ll> balls(n, 0);
		ll tot = 0;
		for (auto& x : balls) {
			sc = scanf("%lld", &x);
			tot += x;
		}
		int av = m - p;
		if (av < tot) {
			printf("-1\n");
			continue;
		}
		if (av == tot) {
			printf("1\n");
			continue;
		}
		vector<vector<ll>> dp(n + 1, vector<ll>(av + 1, -1));
		vector<ll> suffix(n + 1, 0);
		int i = n - 1;
		while (i >= 0) {
			suffix[i] = balls[i] + suffix[i + 1];
			--i;
		}
		ll res = dfs(n, 0, av, dp, suffix, balls);
		printf("%lld\n", res);
	}
	return 0;
}