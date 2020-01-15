class Solution {
public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		if (N == 0)return cells;
		vector<vector<int>> grid(2, vector<int>(8, 0));
		grid[0] = grid[1] = cells;
		int p = 0;
		for (int i = 1; i <= (N % 14) + 14; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (p == 0) {
					if (j == 0 || j == 7)grid[(p + 1) % 2][j] = 0;
					else grid[(p + 1) % 2][j] = (grid[p][j - 1] == grid[p][j + 1]) ? (1) : (0);
				}
				else if (p == 1) {
					if (j == 0 || j == 7)grid[(p + 1) % 2][j] = 0;
					else grid[(p + 1) % 2][j] = (grid[p][j - 1] == grid[p][j + 1]) ? (1) : (0);
				}
			}
			p = !p;
		}
		return grid[p];
	}
};