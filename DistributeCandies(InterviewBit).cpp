int Solution::candy(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	if (n == 1)return 1;
	if (n == 2) {
		if (A[0] == A[1])return 2;
		if (A[0] > A[1])return 3;
		return 3;
	}
	vector<int> candies(n, 1);
	int res = n;
	while (1) {
		int c = 0;
		for (int i = 1; i < n - 1; ++i) {
			int rnl = A[i - 1], rnr = A[i + 1];
			if (A[i - 1] > A[i] && candies[i - 1] <= candies[i]) {
				++candies[i - 1], ++res, ++c;
			}
			if (A[i] > A[i - 1] && candies[i] <= candies[i - 1]) {
				++candies[i], ++res, ++c;
			}
			if (A[i + 1] > A[i] && candies[i + 1] <= candies[i]) {
				++candies[i + 1], ++res, ++c;
			}
			if (A[i] > A[i + 1] && candies[i] <= candies[i + 1]) {
				++candies[i], ++res, ++c;
			}
		}
		if (c == 0)break;
	}
	return res;
}
