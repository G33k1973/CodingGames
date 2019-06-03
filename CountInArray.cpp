#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
using ll = unsigned long long int;
vector<vector<ll>> dp;
ll dfs(int n, int m, int i, int p) {
	//cout<<i<<" "<<p<<endl;
	if (i >= n)return 1;
	if (dp[i][p] != 0)return dp[i][p];
	ll ans = 0;
	if (p == 1) {
		for (int j = 1; j <= m; ++j) {
			ans = (ans%M + dfs(n, m, i + 1, j) % M) % M;
		}
	}
	else
	{
		ans = (ans%M + dfs(n, m, i + 1, p) % M) % M;
		ans = (ans%M + dfs(n, m, i + 1, 1) % M) % M;
		for (int j = 2; j*j <= p; ++j) {
			if (p%j == 0) {
				int d1 = j, d2 = p / j;
				if (d1 == d2)ans = (ans%M + dfs(n, m, i + 1, j) % M) % M;
				else {
					ans = (ans%M + dfs(n, m, i + 1, d1) % M) % M;
					ans = (ans%M + dfs(n, m, i + 1, d2) % M) % M;
				}
			}
		}
		for (int j = p * 2; j <= m; j += p) {
			ans = (ans%M + dfs(n, m, i + 1, j) % M) % M;
		}
	}
	return dp[i][p] = ans;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		dp.assign(n + 1, vector<ll>(m + 1, 0));
		ll res = 0;
		for (int i = 1; i <= m; ++i) {
			//dp.assign(n+1,vector<ll>(m+1,-1));
			res = (res%M + dfs(n, m, 1, i) % M) % M;
		}
		cout << res << "\n";
	}
	return 0;
}