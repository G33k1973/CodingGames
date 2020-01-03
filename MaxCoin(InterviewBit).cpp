int Solution::maxcoin(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return A.front();
	if (n == 2)return max(A.front(), A.back());
	int i, j, gap;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (gap = 1; gap <= n; ++gap) {
		for (i = 0; i <= (n - gap); ++i) {
			j = i + gap - 1;
			if (gap == 1) {
				dp[i][j] = A[i];
				continue;
			}
			int x = (i + 1 <= j - 1) ? (dp[i + 1][j - 1]) : (0);
			int y = (i + 2 <= j) ? (dp[i + 2][j]) : (0);
			int z = (i <= j - 2) ? (dp[i][j - 2]) : (0);
			dp[i][j] = max(A[i] + min(x, y), A[j] + min(x, z));
		}
	}
	return dp[0][n - 1];
}
