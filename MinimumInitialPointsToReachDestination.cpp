#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[15][15][4000];
int dfs(const std::vector<std::vector<int>>& g, int n, int m, int i, int j, int tot, int points, int& res) {
	if (i == (n - 1) && j == (m - 1)) {
		int cum = g[i][j] + tot;
		if (cum <= 0)points += abs(cum) + 1;
		res = std::min(res, points);
		return points;
	}
	if (dp[i][j][tot] != -1) {
		return dp[i][j][tot];
	}
	int ans = 0;
	if (i == (n - 1)) {
		int sub = tot;
		int cum = g[i][j] + tot;
		if (cum <= 0) {
			points += abs(cum) + 1;
			sub = 1;
		}
		else {
			sub = cum;
		}
		ans = dfs(g, n, m, i, j + 1, sub, points, res);
		return dp[i][j][sub] = ans;
	}
	if (j == (m - 1)) {
		int sub = tot;
		int cum = g[i][j] + tot;
		if (cum <= 0) {
			points += abs(cum) + 1;
			sub = 1;
		}
		else {
			sub = cum;
		}
		ans = dfs(g, n, m, i + 1, j, sub, points, res);
		return dp[i][j][sub] = ans;
	}
	int sub = tot;
	int cum = g[i][j] + tot;
	if (cum <= 0) {
		points += abs(cum) + 1;
		sub = 1;
	}
	else {
		sub = cum;
	}
	ans = std::min(dfs(g, n, m, i + 1, j, sub, points, res), dfs(g, n, m, i, j + 1, sub, points, res));
	return dp[i][j][sub] = ans;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		memset(dp, -1, sizeof(dp));
		vector<vector<int>> grid(n, vector<int>(m, 0));
		for (int i = 0; i < n*m; ++i) {
			int I = i / m, J = i % m;
			cin >> grid[I][J];
		}
		int res = INT_MAX;
		dfs(grid, n, m, 0, 0, 0, 0, res);
		cout << max(1, res) << "\n";
	}
	return 0;
}