#define pb push_back
vector<int> Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return vector<int>{};
	if (n == 1)return vector<int>{0};
	vector<int> B;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			B.pb(A[i] * A[i + 1]);
		}
		else if (i == (n - 1)) {
			B.pb(A[i] * A[i - 1]);
		}
		else {
			B.pb(A[i - 1] * A[i + 1]);
		}
	}
	return B;
}
