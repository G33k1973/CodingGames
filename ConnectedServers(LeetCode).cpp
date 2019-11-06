#define pb push_back
class Solution {
protected:
	unordered_map<int, unordered_set<int>> graph;
	vector<vector<int>> result;
	vector<bool> visited;
	int n;
	void dfs(int& total, int src) {
		visited[src] = true;
		for (auto& x : graph[src]) {
			if (!visited[x]) {
				dfs(total, x);
			}
		}
		--total;
	}
	bool isconnected(int u, int v) {
		graph[u].erase(v);
		graph[v].erase(u);
		visited.assign(n, false);
		int tot = n;
		dfs(tot, 0);
		graph[u].insert(v);
		graph[v].insert(u);
		return tot == 0;
	}
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		if (n == 0)return result;
		if (n == 1) {
			result.pb(vector<int>{connections[0][0], connections[0][1]});
			return result;
		}
		for (auto& x : connections) {
			graph[x[0]].insert(x[1]);
			graph[x[1]].insert(x[0]);
		}
		this->n = n;
		for (auto& x : connections) {
			int u = x.front(), v = x.back();
			if (!isconnected(u, v))result.pb(x);
		}
		return result;
	}
};