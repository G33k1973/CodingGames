class Solution {
public:
	int numDecodings(string s) {
		int l = static_cast<int>(s.length());
		int dp[l + 1];
		memset(dp, 0, sizeof(dp));
		if (s.front() == '0')return 0;
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= l; ++i) {
			int num = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
			if (num == 0)return 0;
			if (s[i - 1] == '0') {
				if (num < 30)dp[i] = dp[i - 2];
				else return 0;
			}
			else {
				if (num >= 1 && num <= 26) {
					if (s[i - 2] != '0')dp[i] = dp[i - 2] + dp[i - 1];
					else dp[i] = dp[i - 2];
				}
				else dp[i] = dp[i - 1];
			}
		}
		return dp[l];
	}
};