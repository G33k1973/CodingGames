using ip = pair<int, int>;
using iip = pair<ip, int>;
#define pb push_back
#define mp make_pair
class Solution {
private:
	int n, m;
	int X[4] = { 1,-1,0,0 };
	int Y[4] = { 0,0,-1,+1 };
	map<int, pair<int, int>> bst;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	int bfs(const vector<vector<int>>& g, int& is, int& js, int id, int jd) {
		if (g[is][js] == 0)return -1;
		int c = 0;
		std::queue<iip> pile;
		pile.push(make_pair(make_pair(is, js), 0));
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		visited[is][js] = true;
		while (!pile.empty()) {
			int sz = int(pile.size());
			int i = 0;
			while (i < sz) {
				iip current = pile.front();
				pile.pop();
				int oi = current.first.first;
				int oj = current.first.second;
				int w = current.second;
				if (oi == id && oj == jd) {
					is = id, js = jd;
					return w;
				}
				for (int j = 0; j < 4; ++j) {
					int ni = oi + X[j];
					int nj = oj + Y[j];
					if (isvalid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 0) {
						visited[ni][nj] = true;
						pile.push(mp(mp(ni, nj), w + 1));
					}
				}
				++i;
			}
		}
		return -1;
	}
public:
	int cutOffTree(vector<vector<int>>& forest) {
		n = int(forest.size());
		if (n == 0)return -1;
		m = int(forest.front().size());
		if (m == 0)return -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int y = forest.at(i).at(j);
				if (y > 1)bst.insert(mp(y, mp(i, j)));
			}
		}
		if (bst.size() == 0)return 0;
		std::map<int, pair<int, int>>::const_iterator ptr = bst.begin();
		int is = 0, js = 0;
		int res = 0;
		while (ptr != bst.end()) {
			int id = ptr->second.first;
			int jd = ptr->second.second;
			int cum = this->bfs(forest, is, js, id, jd);
			if (cum == -1)return -1;
			res += cum;
			++ptr;
		}
		return res;
	}
};