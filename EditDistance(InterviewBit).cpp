int Solution::minDistance(string A, string B) {
	int n = int(A.size());
	int m = int(B.size());
	if (n == 0)return m;
	if (m == 0)return n;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == 0)dp[i][j] = j;
			else if (j == 0)dp[i][j] = i;
			else if (A[i - 1] == B[j - 1])dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
			}
		}
	}
	return dp[n][m];
}
