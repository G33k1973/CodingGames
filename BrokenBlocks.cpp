#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		int mx[n][m] = { 0 };
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				cin >> mx[i][j];
			}
		}
		int dp[n][m] = { 0 };
		for (j = 0; j < m; ++j) {
			dp[n - 1][j] = mx[n - 1][j];
		}
		for (i = n - 2; i >= 0; --i) {
			for (j = 0; j < m; ++j) {
				if (mx[i][j] == -1) {
					dp[i][j] = -1;
					continue;
				}
				int acc = INT_MIN;
				if (j - 1 >= 0 && dp[i + 1][j - 1] != -1) {
					acc = max(acc, dp[i + 1][j - 1]);
				}
				if (j + 1 < m&&dp[i + 1][j + 1] != -1) {
					acc = max(acc, dp[i + 1][j + 1]);
				}
				if (dp[i + 1][j] != -1)acc = max(acc, dp[i + 1][j]);
				if (acc == INT_MIN)dp[i][j] = mx[i][j];
				else dp[i][j] = mx[i][j] + acc;
			}
		}
		int res = INT_MIN;
		for (j = 0; j < m; ++j) {
			res = max(res, dp[0][j]);
		}
		cout << max(0, res) << "\n";
	}
	return 0;
}