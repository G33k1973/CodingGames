#define pb push_back
class Solution {
private:
	unordered_map<int, vector<int>> graph;
	vector<bool> visited;
	int N;
	void dfs(int src, int& c) {
		visited[src] = true;
		for (auto& x : graph[src]) {
			if (x == -1)continue;
			if (!visited[x]) {
				dfs(x, c);
			}
		}
		++c;
	}
	bool isConnected(int src) {
		visited.assign(N, false);
		visited.at(src) = true;
		int c(0);
		dfs(src, c);
		return c == N;
	}
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		N = n;
		vector<vector<int>> result;
		if (n == 0)return result;
		for (vector<int>& i : connections) {
			int u = i.front();
			int v = i.back();
			assert(min(u, v) >= 0 && max(u, v) < N);
			graph[u].pb(v);
			graph[v].pb(u);
		}
		for (vector<int>& i : connections) {
			int u = i.front();
			int v = i.back();
			auto it = graph.find(u);
			for (int & j : it->second) {
				if (j == v)j = -1;
			}
			it = graph.find(v);
			for (int & j : it->second) {
				if (j == u)j = -1;
			}
			if (!isConnected(u)) {
				result.pb(vector<int>{u, v});
			}
			for (int & j : it->second) {
				if (j == -1)j = u;
			}
			it = graph.find(u);
			for (int & j : it->second) {
				if (j == -1)j = v;
			}
		}
		return result;
	}
};