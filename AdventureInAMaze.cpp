#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define M 1000000007
bool isvalid(int i, int j, int n) {
	return (i >= 0 && j >= 0 && i < n&&j < n);
}

void dfs(std::vector<vector<int>>& g, int n, int i, int j, int& tot, int sum, int *ans) {
	if (i == n - 1 && j == n - 1) {
		tot = (tot%M + 1) % M;
		*ans = std::max(*ans, sum);
		return;
	}
	int val = g[i][j];
	g[i][j] = 0;
	if (val == 1) {
		int ni = i, nj = j + 1;
		if (isvalid(ni, nj, n) && g[ni][nj] > 0) {
			dfs(g, n, ni, nj, tot, sum + g[ni][nj], ans);
		}
	}
	else if (val == 2) {
		int ni = i + 1, nj = j;
		if (isvalid(ni, nj, n) && g[ni][nj] > 0) {
			dfs(g, n, ni, nj, tot, sum + g[ni][nj], ans);
		}
	}
	else if (val == 3) {
		int ni = i, nj = j + 1;
		if (isvalid(ni, nj, n) && g[ni][nj] > 0) {
			dfs(g, n, ni, nj, tot, sum + g[ni][nj], ans);
		}
		ni = i + 1, nj = j;
		if (isvalid(ni, nj, n) && g[ni][nj] > 0) {
			dfs(g, n, ni, nj, tot, sum + g[ni][nj], ans);
		}
	}
	g[i][j] = val;
	return;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		std::vector<vector<int>> g(n, vector<int>(n, 0));
		for (auto& x : g) {
			for (auto& y : x)
				cin >> y;
		}
		std::vector<vector<int>> sum(n, vector<int>(n, 0));
		std::vector<vector<int>> paths(n, vector<int>(n, 0));
		sum[0][0] = g[0][0];
		paths[0][0] = 1;
		int i, j;
		for (i = 1; i < n; ++i) {
			if (g[i - 1][0] == 1) {
				break;
			}
			else {
				sum[i][0] = sum[i - 1][0] + g[i][0];
				paths[i][0] = 1;
			}
		}
		for (j = 1; j < n; ++j) {
			if (g[0][j - 1] == 2) {
				break;
			}
			else {
				sum[0][j] = g[0][j] + sum[0][j - 1];
				paths[0][j] = 1;
			}
		}
		for (i = 1; i < n; ++i) {
			for (j = 1; j < n; ++j) {
				if (paths[i - 1][j] && (g[i - 1][j] == 2 || g[i - 1][j] == 3)) {
					sum[i][j] = (g[i][j] % M + sum[i - 1][j] % M) % M;
					paths[i][j] = paths[i - 1][j];
				}
				if (paths[i][j - 1] && (g[i][j - 1] == 1 || g[i][j - 1] == 3)) {
					sum[i][j] = max(sum[i][j], (g[i][j] % M + sum[i][j - 1] % M) % M);
					paths[i][j] = (paths[i][j] % M + paths[i][j - 1] % M) % M;
				}
			}
		}
		int tot = paths[n - 1][n - 1];
		int ans = sum[n - 1][n - 1];
		cout << tot << " " << ans << "\n";
	}
	return 0;
}