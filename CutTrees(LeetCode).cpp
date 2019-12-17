#define pb push_back
#define mp make_pair
using ip = pair<int, int>;
using iip = pair<ip, int>;
class Solution {
protected:
	int n, m;
	std::map<int, ip> trees;
	int X[4] = { 0,0,+1,-1 };
	int Y[4] = { +1,-1,0,0 };
	bool isgood(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	int bfs(vector<vector<int>>& forest, int& is, int& js, std::map<int, ip>::iterator ptr) {
		int idst = ptr->second.first;
		int jdst = ptr->second.second;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		visited[is][js] = 0;
		std::queue<iip> pile;
		pile.push(mp(mp(is, js), 0));
		while (!pile.empty()) {
			int sz = int(pile.size());
			int u = 0;
			while (u < sz) {
				iip temp = pile.front();
				pile.pop();
				int oi = temp.first.first;
				int oj = temp.first.second;
				int w = temp.second;
				if (oi == idst && oj == jdst) {
					is = idst, js = jdst;
					return w;
				}
				for (int v = 0; v < 4; ++v) {
					int ni = oi + X[v], nj = oj + Y[v];
					if (isgood(ni, nj) && !visited[ni][nj] && forest[ni][nj] > 0) {
						visited[ni][nj] = true;
						pile.push(mp(mp(ni, nj), w + 1));
					}
				}
				++u;
			}
		}
		return -1;
	}
public:
	int cutOffTree(vector<vector<int>>& forest) {
		this->n = static_cast<int>(forest.size());
		if (n == 0)return 0;
		this->m = static_cast<int>(forest.front().size());
		if (m == 0)return 0;
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (forest[i][j] > 1) {
					trees.insert(mp(forest[i][j], mp(i, j)));
				}
			}
		}
		if (trees.empty())return 0;
		std::map<int, ip>::iterator ptr = begin(trees);
		int res = 0;
		int ip(0), jp(0);
		while (ptr != end(trees)) {
			int sub = bfs(forest, ip, jp, ptr);
			if (sub == -1)return -1;
			res += sub;
			++ptr;
		}
		return res;
	}
};