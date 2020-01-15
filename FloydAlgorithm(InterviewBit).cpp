#define INF 0X3f3f3f3f
vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return vector<vector<int>>{};
	int m = int(A.front().size());
	assert(n == m);
	vector<vector<int>> dp(A);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dp[i][j] == -1)dp[i][j] = INF;
		}
	}
	int i, j, k;
	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (dp[i][k] + dp[k][j] < dp[i][j])dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (dp[i][j] == INF)dp[i][j] = -1;
		}
	}
	return dp;
}
