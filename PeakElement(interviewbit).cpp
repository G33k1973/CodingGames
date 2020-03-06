int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return -1;
	if (n == 1)return A[0];
	int i = 0;
	while (i < n) {
		if (i == 0) {
			if (A[i] >= A[i + 1])return A[i];
		}
		else if (i != (n - 1)) {
			if (A[i] >= max(A[i - 1], A[i + 1]))return A[i];
		}
		else if (i == (n - 1)) {
			if (A[i] >= A[i - 1])return A[i];
		}
		++i;
	}
	return -1;
}
