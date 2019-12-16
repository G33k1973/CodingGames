class Solution {
private:
	int n, m;
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
		(*this).n = static_cast<int>(grid.size());
		if (n == 0)return 0;
		(*this).m = static_cast<int>(grid.front().size());
		if (m == 0)return 0;
		int i, j, res(0);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				char x = grid.operator[](i).operator[](j);
				if (x == 'W' || x == 'E')continue;
				int r = i - 1, c = j;
				int sub(0);
				while (r >= 0) {
					x = grid[r][c];
					if (x == 'W')break;
					if (x == 'E')++sub;
					--r;
				}
				r = i, c = j - 1;
				while (c >= 0) {
					x = grid[r][c];
					if (x == 'W')break;
					if (x == 'E')++sub;
					--c;
				}
				r = i, c = j + 1;
				while (c < m) {
					x = grid[r][c];
					if (x == 'W')break;
					if (x == 'E')++sub;
					++c;
				}
				r = i + 1, c = j;
				while (r < n) {
					x = grid[r][c];
					if (x == 'W')break;
					if (x == 'E')++sub;
					++r;
				}
				res = max(res, sub);
			}
		}
		return res;
	}
};