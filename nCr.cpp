#include<bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;
vector<vector<ll>> dp;
#define N 1005
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
void init() {
	dp.assign(N + 1, vector<ll>(N + 1, 0));
	int i, j;
	for (i = 0; i <= N; ++i) {
		for (j = 0; j <= i; ++j) {
			if (j == 0 || i == j)dp[i][j] = 1;
			else {
				dp[i][j] = ms(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
	return;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	init();
	while (q--) {
		int n, r;
		cin >> n >> r;
		cout << dp[n][r] << "\n";
	}
}