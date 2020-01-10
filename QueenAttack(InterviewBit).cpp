vector<vector<int> > Solution::queenAttack(vector<string> &A) {
	int n = int(A.size());
	if (n == 0)return vector<vector<int>>{ {}};
	int m = int(A.front().size());
	if (m == 0)return vector<vector<int>>{ {}};
	vector<vector<int>> sol(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			{
				int sub = 0;
				int row = i - 1, col = j;
				while (row >= 0) {
					if (A[row][j] == '1') {
						++sub;
						break;
					}
					--row;
				}
				row = i + 1, col = j;
				while (row < n) {
					if (A[row][j] == '1') {
						++sub;
						break;
					}
					++row;
				}
				row = i, col = j - 1;
				while (col >= 0) {
					if (A[row][col] == '1') {
						++sub;
						break;
					}
					--col;
				}
				row = i, col = j + 1;
				while (col < m) {
					if (A[row][col] == '1') {
						++sub;
						break;
					}
					++col;
				}
				row = i - 1, col = j - 1;
				while (row >= 0 && col >= 0) {
					if (A[row][col] == '1') {
						++sub;
						break;
					}
					--col, --row;
				}
				row = i - 1, col = j + 1;
				while (row >= 0 && col < m) {
					if (A[row][col] == '1') {
						++sub;
						break;
					}
					++col, --row;
				}
				row = i + 1, col = j - 1;
				while (row < n && col >= 0) {
					if (A[row][col] == '1') {
						++sub;
						break;
					}
					--col, ++row;
				}
				row = i + 1, col = j + 1;
				while (row < n && col < m) {
					if (A[row][col] == '1') {
						++sub;
						break;
					}
					++col, ++row;
				}
				sol[i][j] = sub;
			}
		}
	}
	return sol;
}
