class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		vector<int> dp(n, 0);
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') continue;
			if (i - 1 >= 0 && s[i - 1] == '(')
			{
				dp[i] = i - 2 < 0 ? 2 : dp[i - 2] + 2;
			}
			else if (i - 1 >= 0 && (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '('))
			{
				dp[i] = i - dp[i - 1] - 2 < 0 ? dp[i - 1] + 2 : dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};