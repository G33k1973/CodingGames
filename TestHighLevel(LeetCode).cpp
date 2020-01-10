#define pb push_back
class Solution {
private:
	vector<int> sol;
	bool isgood(int x) {
		if (x == 0)return false;
		int seen[10] = { 0 };
		int y = x;
		while (x) {
			int rem = x % 10;
			if (rem == 0)return false;
			if (seen[rem] == 0) {
				if (y%rem != 0)return 0;
				seen[rem]++;
			}
			x /= 10;
		}
		return true;
	}
public:
	vector<int> selfDividingNumbers(int left, int right) {
		for (int i = left; i <= right; ++i) {
			if (isgood(i))sol.pb(i);
		}
		return sol;
	}
};

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		if (n == 0)return 0;
		if (n == 1) {
			if (citations[0] == 0)return 0;
			return 1;
		}
		sort(begin(citations), end(citations), greater<int>());
		int i = 0;
		int res = 0;
		while (i < n) {
			int h = citations[i];
			int left = n - i;
			if (h >= (i + 1))res = max(res, min(i + 1, h));
			++i;
		}
		return res;
	}
};

#define INF 0x3f3f3f3f
class Solution {
protected:
	int n, m;
	int X[4] = { +1,0,-1,0 };
	int Y[4] = { 0,+1,0,-1 };
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	vector<vector<vector<int>>> dp;
	int dfs(vector<vector<int>>& grid, int i, int j, int state) {
		if (state == 0 && i == (n - 1) && j == (m - 1)) {
			int oldval = grid[i][j];
			grid[i][j] = 0;
			if (oldval == 1)return 1 + dfs(grid, n - 1, m - 1, 1);
			else return dfs(grid, n - 1, m - 1, 1);
			grid[i][j] = oldval;
		}
		if (state == 1 && i == 0 && j == 0) {
			return grid[i][j];
		}
		if (dp[i][j][state] != -1)return dp[i][j][state];
		if (grid[i][j] == -1)return dp[i][j][state] = -INF;
		int oldval = grid[i][j];
		grid[i][j] = 0;
		int ans = 0;
		if (state == 0) {
			int ni, nj;
			for (int u = 0; u < 2; ++u) {
				ni = i + X[u];
				nj = j + Y[u];
				if (isvalid(ni, nj)) {
					ans = max(ans, oldval + dfs(grid, ni, nj, state));
				}
			}
		}
		else if (state == 1) {
			int ni, nj;
			for (int u = 2; u < 4; ++u) {
				ni = i + X[u];
				nj = j + Y[u];
				if (isvalid(ni, nj)) {
					ans = max(ans, oldval + dfs(grid, ni, nj, state));
				}
			}

		}
		grid[i][j] = oldval;
		return dp[i][j][state] = ans;
	}
public:
	int cherryPickup(vector<vector<int>>& grid) {
		n = int(grid.size());
		if (n == 0)return 0;
		m = int(grid[0].size());
		if (m == 0)return 0;
		if (grid[0][0] == -1 || grid[n - 1][m - 1] == -1)return 0;
		dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));
		int result = dfs(grid, 0, 0, 0);
		if (result < 0)return -1;
		return result;
	}
};


