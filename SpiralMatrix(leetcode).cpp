#define pb push_back
class Solution {
private:
	int n, m;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	int dir = 0, tot = 0;
	vector<int> r;
	void dfs(vector<vector<int>>& grid, int i, int j, int c) {
		r.pb(grid[i][j]);
		if (c == tot)return;
		static int X[4] = { 0,+1,0,-1 };
		static int Y[4] = { +1,0,-1,0 };
		grid[i][j] = INT_MIN;
		int ni, nj;
		while (1) {
			if (dir == 0) {
				ni = i + X[dir], nj = j + Y[dir];
				if (isvalid(ni, nj) && grid[ni][nj] != INT_MIN) {
					dfs(grid, ni, nj, c + 1);
					break;
				}
				dir = (dir + 1) % 4;
			}
			if (dir == 1) {
				ni = i + X[dir], nj = j + Y[dir];
				if (isvalid(ni, nj) && grid[ni][nj] != INT_MIN) {
					dfs(grid, ni, nj, c + 1);
					break;
				}
				dir = (dir + 1) % 4;
			}
			if (dir == 2) {
				ni = i + X[dir], nj = j + Y[dir];
				if (isvalid(ni, nj) && grid[ni][nj] != INT_MIN) {
					dfs(grid, ni, nj, c + 1);
					break;
				}
				dir = (dir + 1) % 4;
			}
			if (dir == 3) {
				ni = i + X[dir], nj = j + Y[dir];
				if (isvalid(ni, nj) && grid[ni][nj] != INT_MIN) {
					dfs(grid, ni, nj, c + 1);
					break;
				}
				dir = (dir + 1) % 4;
			}
		}
	}
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		n = int(matrix.size());
		if (n == 0)return r;
		m = int(matrix.front().size());
		if (m == 0)return r;
		tot = n * m;
		dfs(matrix, 0, 0, 1);
		return r;
	}
};