vector<vector<int>> dp;
int dfs(vector<int>& a, int n, int j, int b) {
	if (j >= (n - 1))return 0;
	if (b == 0)return 0;
	if (dp[j][b] != -1)return dp[j][b];
	int ans = INT_MIN;
	ans = max(ans, dfs(a, n, j + 1, b));
	for (int k = j + 1; k < n; ++k) {
		if (a[k] > a[j])ans = max(ans, a[k] - a[j] + dfs(a, n, k + 1, b - 1));
	}
	return dp[j][b] = ans;
}
int Solution::solve(vector<int> &A, int B) {
	int n = int(A.size());
	if (n == 0)return 0;
	if (B > n)B = n / 2;
	dp.assign(n + 1, vector<int>(B + 1, -1));
	int res = dfs(A, n, 0, B);
	return res;
}
