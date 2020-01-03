int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	if (A[0][0] == 1)return 0;
	vector<vector<int>> dp(n, vector<int>(m, 0));
	dp[0][0] = 1;
	for (int i = 1; i < n; ++i) {
		if (A[i][0] == 0)dp[i][0] = 1;
		else break;
	}
	for (int j = 1; j < m; ++j) {
		if (A[0][j] == 0)dp[0][j] = 1;
		else break;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (A[i][j] == 1)continue;
			if (A[i - 1][j] == 0 && A[i][j - 1] == 0)dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			else if (A[i - 1][j] == 0 && A[i][j - 1] == 1)dp[i][j] += dp[i - 1][j];
			else if (A[i - 1][j] == 1 && A[i][j - 1] == 0)dp[i][j] += dp[i][j - 1];
			else if (A[i - 1][j] == 1 && A[i][j - 1] == 1)dp[i][j] = 0;
		}
	}
	return dp[n - 1][m - 1];
}
