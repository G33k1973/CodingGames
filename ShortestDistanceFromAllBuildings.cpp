using ip = std::pair<int, int>;
using iip = std::pair<ip, int>;
#define pb push_back
int x[] = { 1,-1,0,0 };
int y[] = { 0,0,-1,+1 };
class Solution {
protected:
	int n, m;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	vector<bool> visited;
	int bfs(const std::pair<int, int>& cur, const std::vector<vector<int>>& grid, int tot) {
		visited.assign(n*m, false);
		int i = cur.first;
		int j = cur.second;
		visited.operator[](i*m + j) = static_cast<int>(1);
		std::queue<iip> pile;
		pile.push({ {i,j},0 });
		int distance = 0;
		while (!pile.empty()) {
			int sz = static_cast<int>(pile.size());
			int u = 0;
			while (u < sz) {
				iip temp = pile.front();
				pile.pop();
				int oi = temp.first.first;
				int oj = temp.first.second;
				int weight = temp.second;
				if (grid[oi][oj] == 1) {
					++u;
					distance += weight;
					--tot;
					if (tot == 0)return distance;
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int ni = oi + x[k];
					int nj = oj + y[k];
					if (isvalid(ni, nj) && !visited.at(ni*m + nj) && grid[ni][nj] != 2) {
						visited[ni*m + nj] = true;
						pile.push({ {ni,nj},weight + 1 });
					}
				}
				++u;
			}
		}
		if (tot != 0)return INT_MAX;
		return distance;
	}
public:
	int shortestDistance(vector<vector<int>>& grid) {
		this->n = static_cast<int>(grid.size());
		if (n == 0)return 0;
		this->m = static_cast<int>(grid[0].size());
		if (m == 0)return 0;
		int cbuil(0);
		int i, j;
		vector<ip> gcells;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				int x = grid.at(i).at(j);
				if (x == 0) {
					gcells.pb(std::make_pair(i, j));
				}
				else if (x == 1) {
					++cbuil;
				}
			}
		}
		if (gcells.empty() ^ 0) {
			return -1;
		}
		int res = INT_MAX;
		for (const auto& x : gcells) {
			res = std::min(res, this->bfs(x, grid, cbuil));
		}
		return (res == INT_MAX) ? (-1) : (res);
	}
};