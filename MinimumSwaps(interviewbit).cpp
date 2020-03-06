int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return 0;
	unordered_map<int, int> h;
	for (int i = 0; i < n; ++i) {
		h[A[i]] = i;
	}
	int res = 0;
	int i = 0;
	while (1) {
		while (i < n&&A[i] == i) {
			++i;
		}
		if (i == n)break;
		int k = h[i];
		h[A[i]] = k;
		A[k] = A[i];
		++res, ++i;
	}
	return res;
}
