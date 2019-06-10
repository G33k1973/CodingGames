#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, x, y;
		cin >> n >> x >> y;
		if (x == y && x == 1) {
			if (n & 1) {
				cout << "G\n";
			}
			else {
				cout << "N\n";
			}
			continue;
		}
		if (x == y) {
			int dp[n + 1] = { 0 };
			for (int i = 1; i <= n; ++i) {
				if (dp[i - 1] == 0 || (i >= x && dp[i - x] == 0))dp[i] = 1;
			}
			if (dp[n] == 1)cout << "G\n";
			else cout << "N\n";
		}
		else {
			int dp[n + 1] = { 0 };
			int a = min(x, y);
			int b = max(x, y);
			for (int i = 1; i <= n; ++i) {
				if (dp[i - 1] == 0 || (i >= a && dp[i - a] == 0) || (i >= b && dp[i - b] == 0))dp[i] = 1;
			}
			if (dp[n] == 1)cout << "G\n";
			else cout << "N\n";
		}
	}
	return 0;
}