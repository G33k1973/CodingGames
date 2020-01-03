int Solution::lis(const vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	if (n == 1)return 1;
	vector<int> dp(n, 1);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (A[i] > A[j] && dp[i] < 1 + dp[j])dp[i] = 1 + dp[j];
		}
	}
	return *max_element(begin(dp), end(dp));
}
