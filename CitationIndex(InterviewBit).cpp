int Solution::solve(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	sort(begin(A), end(A), greater<int>());
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int lval = i + 1;//lval papers
		if (lval > A[i]) {
			break;
		}
		int left = n - i - 1;
		if (left == (n - lval))res = max(res, lval);
	}
	return res;
}
