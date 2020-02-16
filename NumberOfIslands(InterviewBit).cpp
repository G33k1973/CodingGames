int X[8] = { 1,1,1,0,0,-1,-1,-1 };
int Y[8] = { -1,0,+1,-1,+1,-1,0,+1 };
bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
void dfs(const vector<vector<int> > &A, int i, int j, int n, int m, vector<vector<bool>>& visited) {
	visited[i][j] = true;
	for (int u = 0; u < 8; ++u) {
		int ni = i + X[u];
		int nj = j + Y[u];
		if (isvalid(ni, nj, n, m) && !visited[ni][nj] && A[ni][nj]) {
			dfs(A, ni, nj, n, m, visited);
		}
	}
	return;
}
int Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int i, j, res = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (A[i][j] == 1 && !visited[i][j]) {
				dfs(A, i, j, n, m, visited);
				++res;
			}
		}
	}
	return res;
}
