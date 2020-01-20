int Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return -1;
	int m = int(A.front().size());
	if (m == 0)return -1;
	pair<int, int> ans{ 0,-1 };
	for (int i = 0; i < n; ++i) {
		auto it = upper_bound(A[i].begin(), A[i].end(), 0);
		if (it != end(A[i])) {
			int c = static_cast<int>(A[i].end() - it);
			if (c > ans.first)ans = make_pair(c, i);
		}
	}
	return ans.second;
}
