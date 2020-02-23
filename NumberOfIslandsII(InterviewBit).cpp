bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
int X[4] = { -1,+1,0,0 };
int Y[4] = { 0,0,-1,+1 };
void dfs(const vector<vector<int>>& grid, int i, int j, int n, int m, vector<bool>& visited) {
	visited[i*m + j] = true;
	for (int u = 0; u < 4; ++u) {
		int ni = i + X[u], nj = j + Y[u];
		if (isvalid(ni, nj, n, m) && !visited[ni*m + nj] && grid[ni][nj] == 1) {
			dfs(grid, ni, nj, n, m, visited);
		}
	}
	return;
}
int Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	int i, j;
	vector<bool> visited(n*m, false);
	int res = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (!visited[i*m + j] && A[i][j] == 1) {
				dfs(A, i, j, n, m, visited);
				++res;
			}
		}
	}
	return res;
}
