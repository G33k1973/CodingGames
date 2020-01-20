int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return 1;
	vector<int> B(A.begin(), A.end());
	sort(begin(B), end(B), less<int>());
	int ans{ 0 };
	int mn, mx;
	int mnA, mxA;
	int mnacc = 1, mxacc = 1;
	int i = 0;
	while (i < n) {
		if (mxacc == 1 && mnacc == 1) {
			mn = B[i], mx = B[i];
			mnA = mxA = A[i];
			mxacc = 0, mnacc = 0;
		}
		mx = B[i];
		if (A[i] > mxA)mxA = A[i];
		if (A[i] < mnA)mnA = A[i];
		if(mnA==mn&&mxA==mx){
			++ans;
			mxacc = 1, mnacc = 1;
		}
		++i;
	}
	return ans;
}
