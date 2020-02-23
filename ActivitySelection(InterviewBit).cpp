struct Functor {
	bool operator()(const vector<int>& a, const vector<int>& b) {
		if (a.back() == b.back())return a.front() > b.front();
		return a.back() < b.back();
	}
};
int dfs(vector<vector<int>>& a, int n, int i, int end, vector<bool>& visited) {
	if (i == n)return 0;
	if (a[i].front() >= end) {
		visited[i] = true;
		return 1 + dfs(a, n, i + 1, a[i].back(), visited);
	}
	return dfs(a, n, i + 1, end, visited);
}
int Solution::solve(vector<int> &A, vector<int> &B) {
	int n = int(A.size());
	int m = int(B.size());
	assert(n == m);
	if (n < 2)return n;
	vector<vector<int>> times;
	for (int i = 0; i < n; ++i) {
		times.push_back(vector<int>{A[i], B[i]});
	}
	sort(begin(times), end(times), Functor());
	vector<bool> visited(n, false);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (visited[i])continue;
		res = max(res, 1 + dfs(times, n, i + 1, times[i].back(), visited));
	}
	return res;
}
