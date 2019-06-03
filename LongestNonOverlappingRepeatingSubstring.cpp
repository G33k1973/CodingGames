#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int l;
		string str;
		cin >> l >> str;
		vector<vector<int>> dp(l + 1, vector<int>(l + 1, 0));
		int max = 0, index = 0;
		for (int i = 1; i <= l; i++) {
			for (int j = i + 1; j <= l; j++) {
				if (str[i - 1] == str[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j] > max) {
						max = dp[i][j];
						index = j;
					}

				}
			}
		}
		if (max == 0)
			cout << "-1" << endl; else cout << str.substr(index - max, max) << endl;
	}
	return 0;
}