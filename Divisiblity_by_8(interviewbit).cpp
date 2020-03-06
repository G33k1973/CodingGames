int Solution::solve(string A) {
	int rem = 0;
	int l = int(A.size());
	for (int i = 0; i < l; ++i) {
		rem = (rem * 10 + (A[i] - '0')) % 8;
	}
	return rem == 0;
}
