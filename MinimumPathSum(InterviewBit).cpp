int Solution::minPathSum(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	if (m == 1 && n == 1)return A[0][0];
	vector<vector<int>> dp(n, vector<int>(m, 0));
	dp[0][0] = A[0][0];
	for (int i = 1; i < n; ++i)dp[i][0] = dp[i - 1][0] + A[i][0];
	for (int j = 1; j < m; ++j)dp[0][j] = dp[0][j - 1] + A[0][j];
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			dp[i][j] = A[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n - 1][m - 1];
}