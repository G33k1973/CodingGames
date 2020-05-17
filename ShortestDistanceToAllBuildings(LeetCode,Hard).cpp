class Solution {
public:
	int shortestDistance(vector<vector<int>>& grid) {
		int bldgcnt = 0;
		int retval = INT_MAX;
		vector<vector<int>> distgrid(grid.size(), vector<int>(grid[0].size(), 0));
		vector<vector<int>> bldgs(grid.size(), vector<int>(grid[0].size(), 0));
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					bldgcnt++;
				}
			}
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
					if (!bfs(grid, i, j, visited, distgrid, bldgs, bldgcnt))
						return -1;
				}
			}
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (bldgs[i][j] == bldgcnt)
					retval = min(retval, distgrid[i][j]);
			}
		}
		return retval == INT_MAX ? -1 : retval;
	}

	bool bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited,
		vector<vector<int>> &distgrid, vector<vector<int>> &bldgs, int bldgcnt) {
		vector<pair<int, int>> dirs{ {0,1},{1,0},{-1,0},{0,-1} };
		queue<pair<int, int>> q;
		int dist = 0;
		int cnt = 1;
		q.push({ i,j });
		visited[i][j] = 1;
		while (!q.empty()) {
			int qsize = q.size();
			dist++;
			for (int i = 0; i < qsize; i++) {
				auto curr = q.front();
				q.pop();
				int x = curr.first;
				int y = curr.second;
				for (auto &d : dirs) {
					int x1 = x + d.first;
					int y1 = y + d.second;
					if (x1 < 0 || y1 < 0 || x1 >= grid.size() || y1 >= grid[0].size()
						|| grid[x1][y1] == 2 || visited[x1][y1]) continue;
					visited[x1][y1] = 1;
					if (grid[x1][y1] == 1) {
						cnt++;
						continue;
					}
					else {
						distgrid[x1][y1] += dist;
						bldgs[x1][y1]++;
						q.push({ x1,y1 });
					}
				}
			}
		}
		return cnt == bldgcnt;
	}
};