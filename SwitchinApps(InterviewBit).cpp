int Solution::solve(vector<int> &A, vector<int> &B) {
	int n = int(A.size());
	int m = int(B.size());
	if (n == 0 || m == 0)return 0;
	int i = 0, j = 0;
	int fa = -1, fb = -1, c = 0;
	while (i < n&&j < m) {
		if (A[i] < B[j]) {
			if (fa == -1 && fb == -1) {
				fa = 1, fb = 0;
			}
			else if (fb) {
				fa = 1, fb = 0, ++c;
			}
			++i;
		}
		else if (A[i] > B[j]) {
			if (fa == -1 && fb == -1) {
				fa = 0, fb = 1;
			}
			else if (fa) {
				fa = 0, fb = 1, ++c;
			}
			++j;
		}
	}
	if (i == n && j != m) {
		if (fa)++c;
	}
	if (j == m && i != n) {
		if (fb)++c;
	}
	return c;
}
