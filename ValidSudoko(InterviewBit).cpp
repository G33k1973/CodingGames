int Solution::isValidSudoku(const vector<string> &A) {
	int n = int(A.size());
	int m = int(A[0].size());
	assert(n == m && n == 9);
	int rows[9][10];
	int cols[9][10];
	memset(rows, 0, sizeof(int) * 9 * 10);
	memset(cols, 0, sizeof(int) * 9 * 10);
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (A[i][j] == '.')continue;
			int x = A[i][j] - '0';
			if (rows[i][x] > 0)return 0;
			++rows[i][x];
			if (cols[j][x] > 0)return 0;
			++cols[j][x];
		}
	}
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			int rs = i * 3;
			int re = rs + 2;
			int cs = j * 3;
			int ce = cs + 2;
			int h[10] = { 0 };
			for (int u = rs; u <= re; ++u) {
				for (int v = cs; v <= ce; ++v) {
					if (A[u][v] == '.')continue;
					int x = A[u][v] - '0';
					if (h[x] > 0)return 0;
					++h[x];
				}
			}
		}
	}
	return 1;
}
