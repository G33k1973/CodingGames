#define pb push_back
class Solution {
protected:
	std::vector<vector<int>> g;
	vector<int> path;
	vector<vector<int>> result;
	vector<bool> visited;
	int n;
	void dfs(int src, int dst) {
		visited[src] = true;
		path.pb(src);
		if (src == dst) {
			result.pb(path);
		}
		else {
			for (auto& x : g[src]) {
				if (!visited[x]) {
					dfs(x, dst);
				}
			}
		}
		visited[src] = false;
		path.pop_back();
		return;
	}
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		this->n = static_cast<int>(graph.size());
		g.assign(begin(graph), end(graph));
		visited.assign(n, false);
		dfs(0, n - 1);
		return result;
	}
};