int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return 0;
	if (n == 2)return A[0] * A[1];
	vector<vector<int>> dp(n, vector<int>(n, 0));
	int i, j, cl;
	for (cl = 1; cl <= n; ++cl) {
		for (i = 0; i <= (n - cl); ++i) {
			j = i + cl - 1;
			if (cl == 1)dp[i][j] = 0;
			else {
				dp[i][j] = INT_MAX;
				for (int k = i; k <= j - 1; ++k) {
					int subres = dp[i][k] + dp[k + 1][j] +
						A[i - 1] * A[k] * A[j];
					if (subres < dp[i][j])dp[i][j] = subres;
				}
			}
		}
	}
	return dp[1][n - 1];
}
