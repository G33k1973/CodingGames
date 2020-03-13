int Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	int i, j, res = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			int left = n - i;
			vector<int> dp(left, 0);
			int u, v;
			for (v = j; v < m; ++v) {
				int sub = 0;
				for (u = i; u < n; ++u) {
					dp[u - i] += A[u][v];
					sub += dp[u - i];
					res = max(res, sub);
				}
			}
		}
	}
	return res;
}
