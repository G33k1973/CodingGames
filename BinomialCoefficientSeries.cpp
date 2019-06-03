#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;
vector<vector<ll>> dp;
void init(int n) {
	dp.assign(n + 1, vector<ll>(n + 1, 0));
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= min(n, i); ++j) {
			if (j == 0 || i == j)dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}
void init(vector<ll>& pwA, vector<ll>& pwX, int n, ll A, ll X) {
	pwA.assign(n + 1, 1);
	pwX.assign(n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		pwA[i] = A * pwA[i - 1];
		pwX[i] = X * pwX[i - 1];
	}
	return;
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		ll A, X, n;
		cin >> A >> X >> n;
		init(n);
		vector<ll> pwA, pwX;
		init(pwA, pwX, n, A, X);
		for (int i = 0; i <= n; ++i) {
			ll sub = dp[n][i] * pwA[n - i] * pwX[i];
			cout << sub << " ";
		}
		cout << endl;
	}
}