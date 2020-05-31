class Solution {
protected:
	int n = 0, m = 0;
	vector<vector<vector<int>>> dp;
	bool isgood(int i, int j1, int j2) {
		return (i >= 0 && j1 >= 0 && i < n&&j1 < m&&j2 >= 0 && j2 < m);
	}
	int getMaxUtil(vector<vector<int>>& grid, int x, int y1, int y2)
	{
		if (!isgood(x, y1, y2)) return INT_MIN;

		if (x == n - 1)
			return (y1 == y2) ? grid[x][y1] : (grid[x][y1] + grid[x][y2]);

		if (dp[x][y1][y2] != -1) return dp[x][y1][y2];

		int ans = INT_MIN;

		int temp = (y1 == y2) ? grid[x][y1] : grid[x][y1] + grid[x][y2];

		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1, y2 - 1));
		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1, y2 + 1));
		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1, y2));

		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1 - 1, y2));
		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1 - 1, y2 - 1));
		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1 - 1, y2 + 1));

		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1 + 1, y2));
		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1 + 1, y2 - 1));
		ans = max(ans, temp + getMaxUtil(grid, x + 1, y1 + 1, y2 + 1));

		return (dp[x][y1][y2] = ans);
	}
public:
	int cherryPickup(vector<vector<int>>& grid) {
		this->n = int(grid.size());
		if (!n)return 0;
		this->m = int(grid.front().size());
		if (!m)return 0;
		dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));
		return getMaxUtil(grid, 0, 0, m - 1);
	}
};