int Solution::solve(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	if (n == 1)return 1;
	vector<int> B(A);
	sort(begin(B), end(B), less<int>());
	int res = 0, i = 0;
	int mxa = INT_MIN, mna = INT_MAX;
	int mxb = INT_MIN, mnb = INT_MAX;
	while (i < n) {
		int nx = B.at(i);
		if (mxa == INT_MIN)mxa = A[i];
		else if (A[i] > mxa)mxa = A[i];
		if (mna == INT_MAX)mna = A[i];
		else if (A[i] < mna)mna = A[i];
		if (mnb == INT_MAX)mnb = nx;
		mxb = nx;
		if (mxa == mxb && mna == mnb) {
			++res;
			mxa = INT_MIN, mna = INT_MAX, mnb = INT_MAX;
		}
		++i;
	}
	return res;
}
