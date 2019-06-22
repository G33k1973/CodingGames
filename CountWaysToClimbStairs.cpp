long long countWays(int m) {
	// your code here
	ll res = 0;
	if (m == 0)return 0;
	if (m == 1)return 1;
	if (m == 2)return 2;
	vector<ll> dp(m + 1, 0);
	dp[0] = 1;
	vector<int> steps{ 1,2 };
	for (int i = 0; i < 2; ++i) {
		for (int j = steps[i]; j <= m; ++j) {
			dp[j] += dp[j - steps[i]];
		}
	}
	return dp.at(m);
}