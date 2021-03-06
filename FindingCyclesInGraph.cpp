class Solution {
public:
	vector<int> ans;
	vector<int> color;
	bool dfs(int v, vector<vector<int>>& graph) {
		color[v] = 1;
		for (int i = 0; i < graph[v].size(); i++) {
			if (color[graph[v][i]] == 0) {
				if (dfs(graph[v][i], graph)) {
					return 1;
				}
			}
			else if (color[graph[v][i]] == 1) {
				return 1;
			}
		}
		ans.push_back(v);
		color[v] = 2;
		return 0;
	}
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		color.assign(n, 0);
		for (int i = 0; i < n; i++) {
			if (color[i] == 0 && dfs(i, graph)) {
				continue;
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};