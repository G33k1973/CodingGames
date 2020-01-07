#define pb push_back
int X[4] = { 1,-1,0,0 };
int Y[4] = { 0,0,1,-1 };
bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
bool dfs(vector<string> &A, int n, int m, int i, int j, string& B, int l, int u) {
	if (u == l)return true;
	bool ans = false;
	for (int k = 0; k < 4; ++k) {
		int ni = i + X[k];
		int nj = j + Y[k];
		if (isvalid(ni, nj, n, m) && A[ni][nj] == B[u]) {
			ans = ans || dfs(A, n, m, ni, nj, B, l, u + 1);
		}
	}
	return ans;
}
int Solution::exist(vector<string> &A, string B) {
	int l = int(B.length());
	if (l == 0)return 1;
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	bool ans = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i][j] == B[0]) {
				ans = ans || dfs(A, n, m, i, j, B, l, 1);
				if (ans == true)return 1;
			}
		}
	}
	return 0;
}