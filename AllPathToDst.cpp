class Solution {
private:
	void dfs(const vector<vector<int>>& graph, int src, int dst, vector<bool>& vis,vector<vector<int>>& res,vector<int>& path) {
		vis[src] = 1;
		path.push_back(src);
		if (src == dst) {
			res.push_back(path);
		}
		else {
			for (auto& x : graph[src]) {
				if (!vis[x]) {
					dfs(graph, x, dst, vis, res, path);
				}
			}
		}
		vis[src] = 0;
		path.pop_back();
	}
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<int> path;
		vector<vector<int>> res;
		int N = (int)graph.size();
		vector<bool> visited(N, false);
		dfs(graph, 0, N - 1, visited, res, path);
		return res;
	}
};