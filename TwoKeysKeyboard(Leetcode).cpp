class Solution {
public:
	int minSteps(int n) {
		if (n == 1)return 0;
		int dp[n + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 0, dp[1] = 0;
		for (int i = 2; i <= n; ++i) {
			dp[i] = INT_MAX;
			for (int j = 1; j < i; ++j) {
				if (i%j == 0) {
					dp[i] = min(dp[i], dp[j] + (i / j));
				}
			}
		}
		return dp[n];
	}
};