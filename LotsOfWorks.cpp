#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int dfs(const std::vector<int>& tbook, int n, int i, int days, int mxbook) {
	if (i == n)return 0;
	if (days == 0)return INT_MAX;
	if (dp[i][days] != -1)return dp[i][days];
	int ans = INT_MAX;
	int sub = 0;
	for (int j = i; j < max(n, i + mxbook); ++j) {
		sub += tbook[j];
		ans = std::min(ans, max(sub, dfs(tbook, n, j + 1, days - 1, mxbook)));
	}
	return dp[i][days] = ans;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		int mxbook = n / m;
		mxbook += (n%m);
		vector<int> tbook(n);
		for (auto& x : tbook)cin >> x;
		memset(dp, -1, sizeof(dp));
		int res = dfs(tbook, n, 0, m, mxbook);
		cout << res << endl;
	}
	return 0;
}