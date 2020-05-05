using iip = std::pair<std::pair<int, int>, int>;
#define mp make_pair
#define pb push_back
class Solution {
protected:
	int n = 0, m = 0;
	int X[4] = { +1,-1,0,0 };
	int Y[4]{ 0,0,-1,+1 };
	bool isgood(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	vector<vector<bool>> visited;
	std::queue<iip> pile;
	void dfs(int i, int j, vector<vector<int>>& board) {
		board[i][j] = 2;
		visited[i][j] = true;
		for (int k = 0; k < 4; ++k) {
			int ni = i + X[k], nj = j + Y[k];
			if (isgood(ni, nj) && !visited[ni][nj]) {
				if (board[ni][nj] == 0) {
					visited[ni][nj] = true;
					pile.push(mp(mp(ni, nj), 0));
				}
				else {
					visited[ni][nj] = true;
					dfs(ni, nj, board);
				}
			}
		}
		return;
	}
public:
	int shortestBridge(vector<vector<int>>& A) {
		n = int(A.size());
		if (n == 0)return -1;
		m = int(A.front().size());
		if (!m)return -1;
		for (auto& x : A) {
			assert(int(x.size()) == m);
		}
		bool out = false;
		visited.assign(n, vector<bool>(m, false));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (A[i][j] == 1) {
					dfs(i, j, A);
					out = !out;
					break;
				}
			}
			if (out)break;
		}
		while (!pile.empty()) {
			int sz = int(pile.size());
			int u = 0;
			while (u < sz) {
				iip current = pile.front();
				pile.pop();
				int oi = current.first.first;
				int oj = current.first.second;
				int w = current.second;
				for (int k = 0; k < 4; ++k) {
					int ni = oi + X[k], nj = oj + Y[k];
					if (isgood(ni, nj) && !visited[ni][nj]) {
						if (A[ni][nj] == 1)return w + 1;
						pile.push(mp(mp(ni, nj), w + 1));
						visited[ni][nj] = true;
					}
				}
				++u;
			}
		}
		return -1;
	}
};