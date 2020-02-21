int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return 1;
	sort(begin(A), end(A));
	int prev = A.front();
	int i = 1;
	while (i < n) {
		if (A[i] != (1 + prev))return false;
		prev = A[i++];
	}
	return 1;
}
