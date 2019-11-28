class Solution {
protected:
	vector<vector<vector<int>>> dp;
	vector<int> sx0, sx1;
	int dfs(vector<vector<int>>& costs, int n, int m, int i, int n0, int n1) {
		if (n0 == m) {
			return sx1[i];
		}
		if (n1 == m) {
			return sx0[i];
		}
		if (dp[i][n0][n1] != -1)return dp[i][n0][n1];
		int ans = INT_MAX;
		ans = min(ans, costs[i][0] + dfs(costs, n, m, i + 1, n0 + 1, n1));
		ans = min(ans, costs[i][1] + dfs(costs, n, m, i + 1, n0, n1 + 1));
		return dp[i][n0][n1] = ans;
	}
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int n = int(costs.size());
		if (n == 0)return 0;
		dp.assign(n + 1, vector<vector<int>>(n / 2, vector<int>(n / 2, -1)));
		sx0.assign(n + 1, 0);
		sx1.assign(n + 1, 0);
		int i = n - 1;
		while (i >= 0) {
			sx0[i] = sx0[i + 1] + costs[i][0];
			sx1[i] = sx1[i + 1] + costs[i][1];
			--i;
		}
		return dfs(costs, n, n / 2, 0, 0, 0);
	}
};