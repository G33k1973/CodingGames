class Solution {
private:
	void dfs(std::unordered_map<int, vector<int>>& grid, int src, vector<bool>& visited, int& ans, int cum) {
		visited.at(src) = true;
		for (auto& x : grid[src]) {
			if (!visited[x]) {
				dfs(grid, x, visited, ans, cum + 1);
			}
		}
		ans += cum;
	}
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		std::unordered_map<int, vector<int>> grid;
		for (auto& x : edges) {
			grid[x[0]].push_back(x[1]);
			grid[x[1]].push_back(x[0]);
		}
		vector<int> a;
		for (int i = 0; i < N; ++i) {
			int res = 0;
			vector<bool> v(N, false);
			dfs(grid, i, v, res, 0);
			a.push_back(res);
		}
		return a;
	}
};