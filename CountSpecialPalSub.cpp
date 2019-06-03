#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 255

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int i, j, cl;
		int res = 0;
		int n = static_cast<int>(s.size());
		int l = n;
		vector<vector<bool>> dp(l, vector<bool>(l, 0));
		for (cl = 1; cl <= n; ++cl) {
			for (i = 0; i <= (n - cl); ++i) {
				j = i + cl - 1;
				if (cl == 1) {
					dp[i][j] = true;
				}
				else if (cl == 2) {
					if (s[i] == s[j]) {
						dp[i][j] = true;
						++res;
					}
					else {
						dp[i][j] = false;
					}
				}
				else {
					char c = s[i + cl / 2 - 1];
					dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j] && s[i] == c);
					if (dp[i][j])++res;
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}