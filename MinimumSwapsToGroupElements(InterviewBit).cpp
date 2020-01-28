int Solution::solve(vector<int> &A, int B) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	if (n == 1) {
		return 0;
	}
	if (n == 2)return 0;
	int sum = 0;
	vector<int> px(n, 0), sx(n, 0);
	for (int i = 0; i < n; ++i) {
		px[i] = sum;
		if (A[i] <= B)++sum;
	}
	for (int i = n - 2; i >= 0; --i) {
		if (A[i + 1] <= B)sx[i] = sx[i + 1] + 1;
		else sx[i] = sx[i + 1];
	}
	int res = n;
	if (sum < 2)return 0;
	for (int i = 0; i <= (n - sum); ++i) {
		int tot = sum - px[i] - sx[i + sum-1];
		res = min(res, sum - tot);
	}
	return res;
}
