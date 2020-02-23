void dfs(string& A, int l, int i, string& B, int m, int j, int& res, int mxgap, int gap, bool& suc) {
	if (j == m) {
		if (!suc)suc = true;
		res = max(res, mxgap);
		res = max(res, l - i);
		return;
	}
	if (i > l)return;
	dfs(A, l, i + 1, B, m, j, res, max(gap + 1, mxgap), gap + 1, suc);
	if (A[i] == B[j])dfs(A, l, i + 1, B, m, j + 1, res, mxgap, 0, suc);
	return;
}
int Solution::solve(string A, string B) {
	int n = int(A.size());
	int m = int(B.size());
	if (m == 0)return n;
	int i = 0, j = 0, k;
	int res = 0;
	while (i < n) {
		if (A[i] == B[0]) {
			bool suc = false;
			dfs(A, n, i + 1, B, m, 1, res, 0, 0, suc);
			if (suc)res = max(res, i);
		}
		++i;
	}
	return res;
}
