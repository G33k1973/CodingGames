int Solution::solve(vector<vector<int> > &A, int B) {
	int n = int(A.size());
	if (n == 0)return -1;
	int m = int(A.front().size());
	if (m == 0)return -1;
	int i, j;
	bool out = false;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (j == 0 && A[i][j] > B) {
				out = !out;
				break;
			}
			if (j == 0 && A[i][m - 1] < B)break;
			auto it = lower_bound(begin(A[i]), end(A[i]), B);
			if (*it != B)break;
			int k = static_cast<int>(it - begin(A[i]));
			return ((i + 1) * 1009 + k + 1);
		}
		if (out)break;
	}
	return -1;
}
