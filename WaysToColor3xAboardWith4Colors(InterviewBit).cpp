#define M 1000000007
int Solution::solve(int A) {
	if (A == 0)return 0;
	if (A == 1)return 36;
	long long int col2 = 12LL, col3 = 24LL;
	for (int i = 2; i <= A; ++i) {
		long long int w = (10LL * col2 + 11LL * col3) % M;
		long long int y = (7LL * col2 + 5LL * col3) % M;
		col2 = y, col3 = w;
	}
	long long int result = (col2%M + col3 % M) % M;
	return static_cast<int>(result);
}
