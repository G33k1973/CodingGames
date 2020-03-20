int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1) {
		if (A[0] & 1)return 1;
		return 0;
	}
	int i = 0;
	int nodd = 0;
	while (i < n) {
		if (A[i] < 0)A[i] = -A[i];
		if (A[i] & 1)++nodd;
		++i;
	}
	int neven = n - nodd;
	return min(neven, nodd);
}
