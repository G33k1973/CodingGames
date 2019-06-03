#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
using ll = long long int;
#define ms(a,b) (((a%M)+(b%M))%M)
vector<vector<ll>> dp;
ll dfs(int n, int i, int sum, int cum) {
	if (cum == sum && i == n)return 1;
	if (cum > sum)return 0;
	if (i > n)return 0;
	if (dp[i][cum] != -1)return dp[i][cum];
	ll ans = 0;
	for (int j = 0; j <= 9; ++j) {
		ans = ms(dfs(n, i + 1, sum, cum + j), ans);
	}
	return dp[i][cum] = ans;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, sum;
		cin >> n >> sum;
		dp.assign(n + 1, vector<ll>(sum + 1, -1));
		ll ans = 0;
		for (int i = 1; i <= 9; ++i) {
			ans = ms(ans, dfs(n, 1, sum, i));
		}
		if (ans == 0)ans = -1;
		cout << ans << "\n";
	}
	return 0;
}