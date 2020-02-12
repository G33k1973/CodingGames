int Solution::solve(vector<int> &A, int B) {
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return 1;
	int res{ 1 };
	int i, j;
	for (i = 0; i < n - 1; ++i) {
		int mxgain = n - i;
		if (mxgain <= res)break;
		int mx = A[i], mn = A[i];
		int sub(0);
		for (j = i; j < n; ++j) {
			int y = A[j];
			mx = max(y, mx);
			mn = min(y, mn);
			if (mx - mn < B)sub = j - i + 1;
			else break;
		}
		res = max(res, sub);
	}
	return res;
}
