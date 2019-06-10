#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
vector<ll> sx, px;
ll sum;
vector<vector<ll>> dp;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)

ll dfs(int n, int i, const std::vector<ll>& arr, ll tot) {
	if (i >= n)return 1;
	if (tot < 0)return 0;
	if (dp[i][tot] != -1)return dp[i][tot];
	ll av = tot - sx[i];
	ll ans = 0;
	for (int j = arr[i]; j <= av; ++j) {
		if (j != av)ans = ms(ans, dfs(n, i + 1, arr, tot - j));
		else ans = ms(ans, 1ULL);
	}
	return dp[i][tot] = ans;
}
#define ITERATIVE_DP
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll candies, taken;
		int n;
		sc = scanf("%lld %d %lld", &candies, &n, &taken);
		ll av = candies - taken;
		vector<ll> arr(n, 0);
		sum = 0;
		px.assign(n, 0);
		int i = 0;
		for (auto& x : arr) {
			sc = scanf("%lld", &x);
			px[i++] = sum;
			sum += x;
		}
		if (av < sum) {
			printf("-1\n");
			continue;
		}
		if (av == sum) {
			printf("1\n");
			continue;
		}
#if !defined ITERATIVE_DP
		sx.assign(n, 0);
		for (int i = n - 2; i >= 0; --i) {
			sx.at(i) = sx.at(i + 1) + arr[i + 1];
		}
#elif defined ITERATIVE_DP
#endif
#if !defined ITERATIVE_DP
		dp.assign(n, vector<ll>(av + 1, -1));
		ll res = dfs(n, 0, arr, av);
#elif defined ITERATIVE_DP
		dp.assign(n + 1, vector<ll>(av + 1, 0));
		for (int i = 0; i <= n; ++i) {
			dp[i][0] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= av; ++j) {
				int mx = j - px[i - 1];
				ll ans = 0;
				for (int k = arr[i - 1]; k <= min(j, mx); ++k) {
					dp[i][j] = ms(dp[i][j], dp[i - 1][j - k]);
				}
			}
		}
		ll res = dp[n][av];
#endif
		printf("%lld\n", res);
	}
}