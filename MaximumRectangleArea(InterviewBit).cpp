int Solution::maximalRectangle(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	int res = 0;
	int i, j, u, v;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (A[i][j] == 0)continue;
			int maxarea = (n - i)*(m - j);
			if (maxarea <= res)break;
			int row = n, col = m;
			vector<int> temp(row - i, 0);
			for (v = j; v < col; ++v) {
				int sub = 0;
				for (u = i; u < row; ++u) {
					temp[u - i] += A[u][v];
					if (temp[u - i] != (v - j + 1)) {
						break;
					}
					sub += temp[u - i];
					res = max(res, sub);
				}
			}
		}
	}
	return res;
}
