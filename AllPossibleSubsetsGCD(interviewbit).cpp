int GCD(int a, int b) {
	if (a == 0)return b;
	return GCD(b%a, a);
}
unordered_set<int> h;
void dfs(vector<int>& a, int n, int i, int g) {
	if (i == n) {
		h.insert(g);
		return;
	}
	dfs(a, n, i + 1, g);
	dfs(a, n, i + 1, GCD(g, a[i]));
	return;
}
int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return n;
	sort(begin(A), end(A));
	auto it = unique(begin(A), end(A));
	A.resize(int(it - begin(A)));
	n = int(A.size());
	if (n < 2)return n;
	if (h.size())h.clear();
	for (int i = 0; i < n; ++i)
		dfs(A, n, i + 1, A[i]);
	return int(h.size());
}
