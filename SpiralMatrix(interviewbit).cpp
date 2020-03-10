#define pb push_back
bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
int X[4] = { 0,+1,0,-1 };
int Y[4] = { +1,0,-1,0 };
void dfs(vector<vector<bool>>& visited, const vector<vector<int>>& grid, vector<int>& out, int i, int j, int n, int m, int c, int tot, int dir) {
	visited[i][j] = true;
	out.pb(grid[i][j]);
	if (c == tot)return;
	int ni, nj;
	while (1) {
		if (dir == 0) {
			ni = i + X[dir], nj = j + Y[dir];
			if (isvalid(ni, nj, n, m) && !visited[ni][nj]) {
				dfs(visited, grid, out, ni, nj, n, m, c + 1, tot, dir);
				break;
			}
			dir = (dir + 1) % 4;
		}
		else if (dir == 1) {
			ni = i + X[dir], nj = j + Y[dir];
			if (isvalid(ni, nj, n, m) && !visited[ni][nj]) {
				dfs(visited, grid, out, ni, nj, n, m, c + 1, tot, dir);
				break;
			}
			dir = (dir + 1) % 4;
		}
		else if (dir == 2) {
			ni = i + X[dir], nj = j + Y[dir];
			if (isvalid(ni, nj, n, m) && !visited[ni][nj]) {
				dfs(visited, grid, out, ni, nj, n, m, c + 1, tot, dir);
				break;
			}
			dir = (dir + 1) % 4;
		}
		else if (dir == 3) {
			ni = i + X[dir], nj = j + Y[dir];
			if (isvalid(ni, nj, n, m) && !visited[ni][nj]) {
				dfs(visited, grid, out, ni, nj, n, m, c + 1, tot, dir);
				break;
			}
			dir = (dir + 1) % 4;
		}
	}
}
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return vector<int>{};
	int m = int(A.front().size());
	if (m == 0)return vector<int>{};
	vector<int> out;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	dfs(visited, A, out, 0, 0, n, m, 1, n*m, 0);
	return out;
}
