bool IsGreater(vector<int>& arr1, vector<int>& arr2) {
	return arr1.front()<arr2.front()&&arr1.back()<arr2.back();
}
int Solution::solve(vector<vector<int> > &A) {
	int n = static_cast<int>(A.size());
	if (n < 2)return n;
	std::sort(begin(A), end(A), [&](const vector<int>& a, const vector<int>& b)->bool {
		return max(a.front(), a.back()) < max(b.front(), b.back()); });
	int i, j;
	int res(0);
	vector<int> dp(n, 1);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (IsGreater(A[j], A[i]) && dp[i] < 1 + dp[j]) {
				dp[i] = 1 + dp[j];
			}
		}
		res = max(res, dp[i]);
	}
	return res;
}
