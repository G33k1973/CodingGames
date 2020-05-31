#define pb push_back
class Solution {
protected:
	std::vector<unordered_map<int, int>> connections;
	vector<bool> r;
	vector<vector<int>> graph;
	vector<bool> isroot;
	void dfs(int src, unordered_map<int, int>& h, int depth) {
		h[src] = depth;
		if (graph[src].empty()) {
			connections.pb(h);
		}
		else {
			for (auto& x : graph[src]) {
				dfs(x, h, depth + 1);
			}
		}
		h.erase(src);
	}
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		if (!r.empty())r.clear();
		if (!n)return vector<bool>{};
		isroot.assign(n, true);
		graph.assign(n, vector<int>());
		for (auto& x : prerequisites) {
			int u = x[0], v = x[1];
			if (isroot[v])isroot[v] = false;
			graph[u].pb(v);
		}
		for (int i = 0; i < n; ++i) {
			if (isroot[i]) {
				unordered_map<int, int> temp;
				dfs(i, temp, 1);
			}
		}
		for (auto& x : queries) {
			int u = x[0], v = x[1];
			bool suc = false;
			for (auto& y : connections) {
				if (y.count(u) && y.count(v) && y[u] < y[v]) {
					suc = true;
					break;
				}
			}
			r.push_back(suc);
		}
		return r;
	}
};