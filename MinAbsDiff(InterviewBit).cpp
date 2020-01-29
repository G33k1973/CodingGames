int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return 0;
	if (n == 2)return abs(A.front() - A.back());
	sort(begin(A), end(A), less<int>());
	int i = 0;
	int res = INT_MAX;
	while (i < n - 1) {
		int val = abs(A[i + 1] - A[i]);
		res = min(res, val);
		++i;
	}
	return res;
}
