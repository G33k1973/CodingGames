#define pb push_back
class Solution {
protected:
	vector<vector<int>> dp;
	int n, k;
	int dfs(int src, vector<vector<int>>& graph, vector<vector<int>>& days, int c) {
		if (c == k)return 0;
		if (dp[src][c] != -1)return dp[src][c];
		int ans = 0;
		ans = max(ans, days[src][c] + dfs(src, graph, days, c + 1));
		for (int i = 0; i < n; ++i) {
			if (i == src)continue;
			if (graph[src][i] == 1) {
				ans = max(ans, days[i][c] + dfs(i, graph, days, c + 1));
			}
		}
		return dp[src][c] = ans;
	}
public:
	int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
		n = static_cast<int>(flights.size());
		if (n == 0)return 0;
		assert(n == int(flights[0].size()));
		assert(n == int(days.size()));
		k = int(days.front().size());
		if (k == 0)return 0;
		dp.assign(n + 1, vector<int>(k + 1, -1));
		return dfs(0, flights, days, 0);
	}
};