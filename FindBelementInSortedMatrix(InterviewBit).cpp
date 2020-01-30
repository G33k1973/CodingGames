int Solution::solve(vector<vector<int> > &A, int B) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	int i = 0;
	vector<int> indexes(n, 0);
	int c = 1, res = 0;
	int prev = A[0][0];
	++indexes[0];
	res = prev;
	while (c < B) {
		pair<int, int> nxt(INT_MAX, -1);
		for (int i = 0; i < n; ++i) {
			int j = indexes[i];
			if (j >= m)continue;
			int x= A[i][j];
			if (x < nxt.first) {
				nxt = make_pair(x, i);
			}
		}
		prev = nxt.first;
		++indexes[nxt.second];
		++c;
	}
	return prev;
}
