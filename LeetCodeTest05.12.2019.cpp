#define pb push_back
class Solution {
protected:
	unordered_set<std::string> seen;
	unordered_map<std::string, int> dict;
	void parse(string& s) {
		s += " ";
		int l = static_cast<int>(s.length());
		string sub = "";
		int i = 0;
		while (i < l) {
			char x = s.at(i);
			if (isalpha(x)) {
				if (isupper(x))x = tolower(x);
				sub.pb(x);
			}
			else {
				if (!sub.empty()) {
					if (seen.count(sub) == 0) {
						++dict[sub];
						sub.clear();
					}
					else sub.clear();
				}
			}
			++i;
		}
	}
	string res;
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		res = "";
		for (auto& x : banned)seen.insert(x);
		parse(paragraph);
		pair<string, int> ans("", INT_MIN);
		for (auto& x : dict) {
			if (x.second > ans.second)ans = make_pair(x.first, x.second);
		}
		return res = ans.first;
	}
};

typedef pair<int, int> ip;
typedef pair<ip, int> iip;
#define pb push_back
#define mp make_pair
int X[4] = { 1,-1,0,0 };
int Y[4] = { 0,0,1,-1 };
class Solution {
protected:
	bool isgood(int i, int j) {
		return (i >= 0 && j >=0 &&i < n&&j < m);
	}
	int n, m;
	std::map<int, pair<int, int>> trees;
	int bfs(int itr, int jtr, int& ipos, int& jpos, vector<vector<int>>& grid) {
		vector<vector<bool>> v(n, vector<bool>(m, false));
		v[ipos][jpos] = true;
		std::queue<iip> pile;
		pile.push(mp(mp(ipos, jpos), 0));
		while (!pile.empty()) {
			int sz = int(pile.size());
			int k = 0;
			while (k < sz) {
				iip current = pile.front();
				pile.pop();
				int oi = current.first.first;
				int oj = current.first.second;
				int w = current.second;
				if (oi == itr && oj == jtr) {
					grid[itr][jtr] = 1;
					ipos = itr, jpos = jtr;
					return w;
				}
				for (int u = 0; u < 4; ++u) {
					int ni = oi + X[u];
					int nj = oj + Y[u];
					if (isgood(ni, nj) && !v[ni][nj] && grid[ni][nj] > 0) {
						pile.push(mp(mp(ni, nj), w + 1));
						v[ni][nj] = 1;
					}
				}
				++k;
			}
		}
		return -1;
	}
public:
	int cutOffTree(vector<vector<int>>& forest) {
		n = int(forest.size());
		if (n == 0)return 0;
		m = int(forest.front().size());
		if (m == 0)return 0;
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (forest[i][j] > 1) {
					trees.insert(make_pair(forest[i][j], make_pair(i, j)));
				}
			}
		}
		auto ptr = begin(trees);
		int res = 0;
		pair<int, int> pos(0, 0);
		while (ptr != end(trees)) {
			int sub=bfs(ptr->second.first, ptr->second.second, pos.first, pos.second, forest);
			if (sub == -1)return -1;
			res += sub;
			++ptr;
		}
		return res;
	}
};