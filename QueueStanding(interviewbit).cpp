int Solution::solve(int A) {
	long long int pw2 = 1LL;
	while (1) {
		long long int sub = (pw2 << 1);
		if (sub > static_cast<long long int>(A))break;
		pw2 = sub;
	}
	return pw2;
}
