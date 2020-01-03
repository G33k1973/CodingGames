int Solution::numDecodings(string A) {
	int l = int(A.length());
	if (l == 0)return 0;
	if (l == 1) {
		if (A[0] == '0')return 0;
		return 1;
	}
	vector<int> dp(l, 0);
	if (A[0] == '0')return 0;
	dp[0] = 1;
	for (int i = 1; i < l; ++i) {
		if (A[i - 1] == '0'&&A[i] == '0')return 0;
		if (A[i - 1] == '0') {
			dp[i] = dp[i - 1];
		}
		else {
			int num = 10 * (A[i - 1] - '0') + (A[i] - '0');
			if (num <= 26) {
				if (A[i] != '0') {
					if (i >= 2)dp[i] = dp[i - 2] + dp[i - 1];
					else dp[i] = dp[i - 1];
				}
				else dp[i] = dp[i - 1];
			}
			else {
				if (A[i] == '0')return 0;
				dp[i] = dp[i - 1];
			}
		}
	}
	return dp[l - 1];
}