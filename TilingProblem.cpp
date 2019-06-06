#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define M 1000000007
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		vector<ll> dp(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			if (i < m)dp[i] = 1;
			else if (i == m)dp[i] = 2;
			else {
				dp[i] = (dp[i - m] % M + dp[i - 1] % M) % M;
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}