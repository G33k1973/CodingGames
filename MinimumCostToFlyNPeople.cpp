#define pb push_back
class Solution {
protected:
	vector<int> sx0, sx1;
	vector<vector<vector<int>>> dp;
	int dfs(vector<vector<int>>& a, int n, int n0, int n1, int i) {
		if (n0 == 0) {
			return sx1[i];
		}
		if (n1 == 0) {
			return sx0[i];
		}
		if (dp[i][n0][n1] != -1)
			return dp[i][n0][n1];
		int ans = INT_MAX;
		ans = min(ans, a[i][0] + dfs(a, n, n0 - 1, n1, i + 1));
		ans = min(ans, a[i][1] + dfs(a, n, n0, n1 - 1, i + 1));
		return dp[i][n0][n1] = ans;
	}
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int n = int(costs.size());
		if (n == 0)return 0;
		assert(!(n & 1));
		sx0.assign(n + 1, 0);
		sx1.assign(n + 1, 0);
		int i = n - 1;
		while (i >= 0) {
			sx0[i] = sx0[i + 1] + costs[i][0];
			sx1[i] = sx1[i + 1] + costs[i][1];
			--i;
		}
		dp.assign(n + 1, vector<vector<int>>(n / 2 + 1, vector<int>(n / 2 + 1, -1)));
		return dfs(costs, n, n / 2, n / 2, 0);
	}
};