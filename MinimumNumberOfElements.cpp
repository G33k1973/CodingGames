#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int dp[105][105][105];//index previous_incr previous_decr
int dfs(vector<int>&a, int n, int i, int pd, int pi) {
	if (i == n) {
		return 0;
	}
	if (dp[i][pd][pi] != -1)return dp[i][pd][pi];
	int ans = 0, ans1 = INF, ans2 = INF, ans3 = INF;
	if (a[i] < pd) {
		ans1 = dfs(a, n, i + 1, a[i], pi);
	}
	if (a[i] > pi) {
		ans2 = dfs(a, n, i + 1, pd, a[i]);
	}
	ans3 = 1 + dfs(a, n, i + 1, pd, pi);
	ans = std::min(ans1, std::min(ans2, ans3));
	return dp[i][pd][pi] = ans;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& x : a) {
			cin >> x;
			assert(x > 0 && x <= 100);
		}
		memset(dp, -1, sizeof(dp));
		int res = dfs(a, n, 0, 102, 0);
		cout << res << endl;
	}
	return 0;
}