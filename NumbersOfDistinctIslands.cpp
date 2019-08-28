int x[] = { 1,-1,0,0 };
int y[] = { 0,0,+1,-1 };
class Solution {
protected:
	int n, m;
	vector<vector<pair<int, int>>> islands;
	vector<bool> visited;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& temp) {
		temp.push_back(std::make_pair(i, j));
		visited.at(i*m + j) = true;
		for (int k = 0; k < 4; ++k) {
			int ni = i + x[k];
			int nj = j + y[k];
			if (isvalid(ni, nj) && !visited[ni*m + nj] && grid[ni][nj] == 1) {
				dfs(grid, ni, nj, temp);
			}
		}
		return;
	}
public:
	int numDistinctIslands(vector<vector<int>>& grid) {
		int res = 0;
		n = static_cast<int>(grid.size());
		if (n == 0)return 0;
		m = static_cast<int>(grid.front().size());
		if (m == 0)return 0;
		visited.assign(n*m, false);
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (grid[i][j] == 1 && !visited[i*m + j]) {
					vector<pair<int, int>> temp;
					this->dfs(grid, i, j, temp);
					islands.push_back(temp);
				}
			}
		}
		int o = (int)islands.size();
		if (o < 2)return o;
		visited.assign(o, false);
		for (i = 0; i < o; ++i) {
			if (visited[i])continue;
			int i1start = islands[i][0].first;
			int j1start = islands[i][0].second;
			int sz1 = (int)islands[i].size();
			for (j = i + 1; j < o; ++j) {
				int sz2 = (int)islands[j].size();
				if (sz1 != sz2)continue;
				int i2start = islands[j][0].first;
				int j2start = islands[j][0].second;
				int k;
				for (k = 0; k < sz1; ++k) {
					int d1i = islands[i][k].first - i1start;
					int d1j = islands[i][k].second - j1start;
					int d2i = islands[j][k].first - i2start;
					int d2j = islands[j][k].second - j2start;
					if (d1i != d2i || d1j != d2j)break;
				}
				if (k == sz1) {
					visited[j] = true;
				}
			}
			visited[i] = true;
			++res;
		}
		return res;
	}
};