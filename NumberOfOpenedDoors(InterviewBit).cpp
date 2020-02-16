int Solution::solve(int A) {
	int res = 0;
	long long int i = 1;
	while (1) {
		long long int j = i * i;
		if (j > static_cast<long long int>(A))break;
		++i, ++res;
	}
	return res;
}
