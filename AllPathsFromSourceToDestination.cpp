#define pb push_back
class Solution {
protected:
	std::unordered_map<int, vector<int>> g;
	int n;
	vector<vector<int>> res;
	vector<int> temp;
	vector<bool> visited;
	void dfs(int src, int dst) {
		visited[src] = true;
		temp.pb(src);
		if (src == dst) {
			res.pb(temp);
		}
		else {
			for (auto& x : g[src]) {
				if (!visited[x])dfs(x, dst);
			}
		}
		temp.pop_back();
		visited[src] = false;
		return;
	}
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		this->n = static_cast<int>(graph.size());
		if (n == 0)return res;
		for (int i = 0; i < n; ++i) {
			if (graph[i].empty())continue;
			for (const int& y : graph[i]) {
				g[i].pb(y);
			}
		}
		visited.assign(n, false);
		if (temp.size() > 0)temp.clear();
		dfs(0, n - 1);
		return res;
	}
};