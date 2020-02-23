vector<int> Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return A;
	vector<int> B(n, 0);
	for (int i = 0; i < n; ++i) {
		B[A[i]] = i;
	}
	return B;
}
