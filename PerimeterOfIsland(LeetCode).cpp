class Solution {
private:
	int n, m;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	int Acc(int i, int j, const vector<vector<int>>& grid) {
		static int X[4] = { 1,-1,0,0 };
		static int Y[4] = { 0,0,-1,+1 };
		int res = 4;
		for (int k = 0; k < 4; ++k) {
			int ni = i + X[k], nj = j + Y[k];
			if (isvalid(ni, nj) && grid[ni][nj])--res;
		}
		return res;
	}
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		n = int(grid.size());
		if (n == 0)return 0;
		m = int(grid.front().size());
		if (m == 0)return 0;
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 1)res += Acc(i, j, grid);
			}
		}
		return res;
	}
};