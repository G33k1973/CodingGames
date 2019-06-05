#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef unsigned long long int ll;
vector<vector<ll>> dp;
std::map<vector<int>, int> memo;
ll dfs(int n, int k, int tot, const int& sum) {
	//cout<<n<<" "<<k<<endl;
	//n->coins
	//k->pupils
	if (k == 0) {
		if (tot == sum)return 1;
		return 0;
	}
	if (tot > sum)return 0;
	if (tot == sum && k > 0)return 0;
	if ((sum - tot) / k < 1)return 0;
	if (n < k)return 0;
	if (k == n) {
		return 1;
	}
	if (dp[n][k] != 0)return dp[n][k];
	ll ans = 0;
	for (int i = 1; i <= (n - k + 1); ++i) {
		ans = (ans%M + dfs(n - i, k - 1, tot + i, sum) % M) % M;
	}
	return dp[n][k] = ans;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		if (memo.size() > 0)memo.clear();
		int n, k;
		sc = scanf("%d %d", &n, &k);
		dp.assign(n + 1, vector<ll>(k + 1, 0));
		ll res = dfs(n, k, 0, n);
		printf("%llu\n", res);
	}
	return 0;
}