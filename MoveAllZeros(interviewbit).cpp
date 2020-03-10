vector<int> Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return A;
	int i = 0, j = 0;
	while (i < n) {
		if (A[i] == 0)++i;
		else {
			A[j++] = A[i++];
		}
	}
	while (j < n)A[j++] = 0;
	return A;
}
