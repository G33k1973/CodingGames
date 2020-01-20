#define pb push_back
unordered_map<int, vector<int>> h;
int dfs(vector<int>& A, int n, int i, int x1, int x2, int c) {
	if (i == n)return 0;
	int ans = 0;
	if (x2 == INT_MIN) {
		ans = max(ans, dfs(A, n, i + 1, x1, x2, c));
		ans = max(ans, dfs(A, n, i + 1, x1, A[i], c + 1));
	}
	else {
		int x3 = x1 + x2;
		auto it = h.find(x3);
		if (it == end(h))return 0;
		auto it2 = lower_bound(it->second.begin(), it->second.end(), i);
		if (it2 == end(it->second))return 0;
		ans = (c == 2) ? (3 + dfs(A, n, *it2, x2, x3, c + 1)) : (1 + dfs(A, n, *it2, x2, x3, c + 1));
	}
	return ans;
}
int Solution::solve(vector<int> &A) {
	if (h.size() > 0)h.clear();
	int n = int(A.size());
	if (n < 3)return 0;
	int i = 0;
	while (i < n) {
		h[A[i]].pb(i);
		++i;
	}
	int ans = 0;
	for (int i = 0; i < n - 2; ++i) {
		ans = max(ans, dfs(A, n, i + 1, A[i], INT_MIN, 1));
	}
	return ans;
}