int DP[105][105][105];
bool dfs(string& A, string& B, string& C, int n, int m, int o, int i, int j, int k) {
	if (j == m && i == n)return true;
	if (k == o)return false;
	if (DP[i][j][k] != -1)return DP[i][j][k];
	bool ans = false;
	if (j == m) {
		if (A[i] == C[k])ans = ans || dfs(A, B, C, n, m, o, i + 1, j, k + 1);
		else ans = ans || dfs(A, B, C, n, m, o, i, j, k + 1);
	}
	else if (i == n) {
		if (B[j] == C[k])ans = ans || dfs(A, B, C, n, m, o, i, j + 1, k + 1);
		else ans = ans || dfs(A, B, C, n, m, o, i, j, k + 1);
	}
	else {
		if (A[i] == C[k])ans = ans || dfs(A, B, C, n, m, o, i + 1, j, k + 1);
		if (B[j] == C[k])ans = ans || dfs(A, B, C, n, m, o, i, j + 1, k + 1);
		ans = ans || dfs(A, B, C, n, m, o, i, j, k + 1);
	}
	return DP[i][j][k] = ans;
}
bool isInterleave(string A, string B, string C)
{
	//Your code here
	int n = (int)A.length();
	int m = (int)B.length();
	int o = (int)C.length();
	if (o < (n + m))return false;
	memset(DP, -1, sizeof(DP));
	return dfs(A, B, C, n, m, o, 0, 0, 0);
}
