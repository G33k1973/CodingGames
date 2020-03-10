#define pb push_back
class Solution {
private:
	vector<int> result;
public:
	vector<int> selfDividingNumbers(int left, int right) {
		assert(left <= right);
		for (int i = left; i <= right; ++i) {
			int j(i);
			while (j) {
				int rem = j % 10;
				if (rem == 0||i%rem!=0)break;
				j /= 10;
			}
			if (j == 0)result.pb(i);
		}
		return result;
	}
};

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = static_cast<int>(citations.size());
		if (n == 0)return 0;
		sort(begin(citations), end(citations), greater<int>());
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int val = (i + 1);
			//if (val < citations[i])continue;
			val = min(val, citations[i]);
			//cout<<val<<endl;
			int left = n - i;
			if (i == (n - 1) || citations[i + 1] <= val)res = max(res, val);
		}
		return res;
	}
};

#define INF 99999
class Solution {
private:
	int X[4] = { 1,0,-1,0 };
	int Y[4] = { 0,+1,0,-1 };
	vector<vector<vector<int>>> dp;
	vector<vector<bool>> visited;
	int n, m;
	int dfs(vector<vector<int>>& grid, int i, int j, bool firstpath, vector<vector<bool>>& vis) {
		//cout<<i<<" "<<j<<" "<<grid[i][j]<<endl;
		if (grid[i][j] == -1)return -INF;
		vis[i][j] = true;
		int ans = -INF;
		int x = grid[i][j];
		grid[i][j] = 0;
		if (i == (n - 1) && j == (m - 1) && firstpath) {
			//second path starts
			vector<vector<bool>> t(n, vector<bool>(m, false));
			t[i][j] = true;
			int sub = (x == 0) ? (0) : (1);
			for (int k = 2; k < 4; ++k) {
				int ni = i + X[k];
				int nj = j + Y[k];
				if (isvalid(ni, nj) && grid[ni][nj] != -1) {
					ans = max(ans, sub + dfs(grid, ni, nj, !firstpath, t));
				}
			}
		}
		else if (i == 0 && j == 0 && !firstpath) {
			//cycle terminated
			return 0;
		}
		else if (firstpath) {
			//in first path
			int sub = (x == 0) ? (0) : (1);
			for (int k = 0; k < 2; ++k) {
				int ni = i + X[k];
				int nj = j + Y[k];
				if (isvalid(ni, nj) && grid[ni][nj] != -1 && vis[ni][nj] == false) {
					ans = max(ans, sub + dfs(grid, ni, nj, firstpath, vis));
				}
			}
		}
		else if (!firstpath) {
			//in second path
			int sub = (x == 0) ? (0) : (1);
			for (int k = 2; k < 4; ++k) {
				int ni = i + X[k];
				int nj = j + Y[k];
				if (isvalid(ni, nj) && grid[ni][nj] != -1 && vis[ni][nj] == false) {
					ans = max(ans, sub + dfs(grid, ni, nj, firstpath, vis));
				}
			}
		}
		vis[i][j] = false;
		grid[i][j] = x;
		return ans;
	}
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
public:
	int cherryPickup(vector<vector<int>>& grid) {
		n = int(grid.size());
		if (n == 0)return 0;
		m = int(grid[0].size());
		if (m == 0)return 0;
		if (n == 1 && m == 1) {
			if (grid[0][0] == -1)return 0;
			return grid[0][0];
		}
		dp.assign(n, vector<vector<int>>(m, vector<int>(2, -1)));
		visited.assign(n, vector<bool>(m, false));
		int res = dfs(grid, 0, 0, true, visited);
		if (res < 0)res = 0;
		return res;
	}
};