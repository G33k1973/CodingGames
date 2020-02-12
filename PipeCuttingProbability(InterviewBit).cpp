#define M 1e7
using ll = long long int;
int Solution::solve(vector<int> &A, int B) {
	int n = int(A.size());
	if (n == 0)return M;
	assert(B >= 1 && B <= 100);
	sort(begin(A), end(A));
	ll tot = (n & 1) ? (((n - 1) / 2)*n) : ((n / 2)*(n - 1));
	ll cnt = 0;
	int i, j;
	for (i = 0; i < n - 1; ++i) {
		int a = A[i];
		for (j = i + 1; j < n; ++j) {
			int b = A[j] - A[i];
			int c = 100 - A[j];
			if (max(a, max(b, c)) > B)++cnt;
		}
	}
	double ratio = (1.*cnt) / (1.*tot);
	ratio *= M;
	return ratio;
}
