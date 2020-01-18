int Solution::solve(const vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (A[i][j] == 0)continue;
			int row = i + 1, col = j + 1;
			while (col < m) {
				if (A[i][col] == 1) {
					row = i + 1;
					while (row < n) {
						if (A[row][j] == 1 && A[row][col] == 1)return 1;
						++row;
					}
				}
				++col;
			}
		}
	}
	return 0;
}
