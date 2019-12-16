#define pb push_back
#define mp make_pair
using ip = std::pair<int, int>;
class Solution {
protected:
	vector<vector<ip>> collector;
	int n, m;
	int X[4] = { +1,-1,0,0 };
	int Y[4] = { 0,0,+1,-1 };
	bool isgood(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	vector<vector<bool>> visited;
	void dfs(vector<vector<int>>& grid, int i, int j, vector<ip>& temp) {
		visited.at(i).at(j) = true;
		temp.pb(mp(i, j));
		for (int u = 0; u < 4; ++u) {
			int ni = i + X[u], nj = j + Y[u];
			if (isgood(ni, nj) && visited[ni][nj] == false && grid[ni][nj] == 1) {
				dfs(grid, ni, nj, temp);
			}
		}
		return;
	}
	bool equals(const std::vector<ip>& a, const std::vector<ip>& b) {
		int n = int(a.size());
		int m = int(b.size());
		if (n != m)return false;
		int si1 = a[0].first, sj1 = a[0].second;
		int si2 = b[0].first, sj2 = b[0].second;
		for (int i = 1; i < n; ++i) {
			int ni1 = a[i].first, nj1 = a[i].second;
			int ni2 = b[i].first, nj2 = b[i].second;
			int DX1 = ni1 - si1;
			int DY1 = nj1 - sj1;
			int DX2 = ni2 - si2;
			int DY2 = nj2 - sj2;
			if (DX1 != DX2 || DY1 != DY2)return false;
		}
		return true;
	}
public:
	int numDistinctIslands(vector<vector<int>>& grid) {
		n = int(grid.size());
		if (n == 0)return 0;
		m = int(grid[0].size());
		if (m == 0)return 0;
		visited.assign(n, vector<bool>(m, false));
		if (collector.size() > 0)collector.clear();
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (grid[i][j] == 1 && !visited[i][j]) {
					vector<ip> temp;
					dfs(grid, i, j, temp);
					collector.pb(temp);
				}
			}
		}
		int sz = int(collector.size());
		if (sz < 2)return sz;
		bool v[sz];
		int ans = 0;
		memset(v, false, sizeof(bool)*sz);
		for (i = 0; i < sz; ++i) {
			if (v[i])continue;
			for (j = i + 1; j < sz; ++j) {
				if (equals(collector[i], collector[j])) {
					v[j] = true;
				}
			}
			++ans;
		}
		return ans;
	}
};