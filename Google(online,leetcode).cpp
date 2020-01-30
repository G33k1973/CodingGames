#define pb push_back
class Solution {
private:
	std::unordered_set<string> seen;
	int ans;
	void dfs(string& s, int l, int i, string& current) {
		if (i == l) {
			if (current.size()>0 && seen.count(current) == 0) {
				++ans;
				seen.insert(current);
			}
			return;
		}
		current.pb(s[i]);
		dfs(s, l, i + 1, current);
		current.pop_back();
		dfs(s, l, i + 1, current);
	}
public:
	int numTilePossibilities(string tiles) {
		int n = int(tiles.size());
		if (n == 0)return 0;
		if (n == 1)return 1;
		sort(begin(tiles), end(tiles));
		this->ans = 0;
		string temp = "";
		do {
			temp = "";
			dfs(tiles, n, 0, temp);
		} while (next_permutation(begin(tiles), end(tiles)));
		return ans;
	}
};

#define pb push_back
class Solution {
private:
	vector<int> col;
	vector<vector<int>> graph;
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		if (N == 0)return col;
		col.assign(N, -1);
		if (N < 5) {
			col.assign(N, 1);
			std::iota(begin(col), end(col), 1);
			return col;
		}
		graph.assign(N, vector<int>());
		for (const std::vector<int>& i : paths) {
			int u = i.front() - 1;
			int v = i.back() - 1;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		for (int i = 0; i < N; ++i) {
			if (graph[i].size() == 0) {
				col[i] = 1;
				continue;
			}
			unordered_set<int> chosen{ 1,2,3,4 };
			for (auto& j : graph[i]) {
				if (col[j] != -1) {
					chosen.erase(col[j]);
				}
			}
			for (auto& j : chosen) {
				col[i] = j;
				break;
			}
		}
		return col;
	}
};