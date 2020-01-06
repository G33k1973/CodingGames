int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int n = static_cast<int>(A.size());
	int m = static_cast<int>(B.size());
	int o = static_cast<int>(C.size());
	if (n == 0)return 0;
	int maxcap = *max_element(begin(A), end(A));
	vector<int> DP(maxcap + 1, 0);
	DP[0] = 0;
	for (int i = 1; i <= maxcap; ++i) {
		DP[i] = INT_MAX;
		for (int j = 0; j < m; ++j) {
			if (B[j] <= i && DP[i - B[j]] != INT_MAX) {
				DP[i] = min(DP[i], C[j] + DP[i - B[j]]);
			}
		}
	}
	int res(0);
	for (int i = 0; i < n; ++i) {
		res += DP[A[i]];
	}
	return res;
}