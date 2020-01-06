class Solution {
public:
	int minInsertions(string s) {
		int l = int(s.size());
		if (l < 2)return 0;
		vector<vector<int>> dp(l, vector<int>(l, 0));
		int i, j, cl;
		for (cl = 1; cl <= l; ++cl) {
			for (i = 0; i <= (l - cl); ++i) {
				j = i + cl - 1;
				if (cl == 1)
					dp[i][j] = 1;
				else if (cl == 2) {
					dp[i][j] = (s[i] == s[j]) ? (2) : (1);
				}
				else {
					if (s[i] == s[j])dp[i][j] = 2 + dp[i + 1][j - 1];
					else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return (l - dp[0][l - 1]);
	}
};