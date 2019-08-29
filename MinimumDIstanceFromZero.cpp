int x[] = { 1,-1,0,0 };
int y[] = { 0,0,+1,-1 };
class Solution {
	int n, m;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	int bfs(const std::vector<vector<int>>& g, int i, int j) {
		vector<bool> visited(n*m, false);
		visited[i*m + j] = true;
		std::queue<pair<pair<int, int>, int>> pile;
		pile.push({ {i,j},0 });
		while (!pile.empty()) {
			int sz = (int)pile.size();
			int u = 0;
			while (u < sz) {
				pair<pair<int, int>, int> current = pile.front();
				pile.pop();
				int oi = current.first.first;
				int oj = current.first.second;
				int dist = current.second;
				if (g[oi][oj] == 0)return dist;
				for (int k = 0; k < 4; ++k) {
					int ni = oi + x[k];
					int nj = oj + y[k];
					if (isvalid(ni, nj) && !visited[ni*m + nj]) {
						visited[ni*m + nj] = true;
						pile.push({ {ni,nj},dist + 1 });
					}
				}
				++u;
			}
		}
		return -1;
	}
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		vector<vector<int>> res;
		n = (int)matrix.size();
		if (n == 0)return res;
		m = (int)matrix[0].size();
		if (m == 0)return res;
		res.assign(n, vector<int>(m, 0));
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (matrix[i][j] == 1) {
					res[i][j] = this->bfs(matrix, i, j);
				}
			}
		}
		return res;
	}
};