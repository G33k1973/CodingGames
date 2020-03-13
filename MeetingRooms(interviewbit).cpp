void dfs(vector<vector<int>>& a, int n, int i, int endtime, vector<bool>& visited) {
	if (i == n)return;
	if (visited[i])dfs(a, n, i + 1, endtime, visited);
	else {
		if (a[i][0] >= endtime) {
			visited[i] = true;
			dfs(a, n, i + 1, a[i][1], visited);
		}
		else {
			dfs(a, n, i + 1, endtime, visited);
		}
	}
}
int Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return 1;
	sort(begin(A), end(A), [&](const vector<int>& a, const vector<int>& b)->bool {
		if (a[0] == b[0])return a[1] > b[1];
		return a[0] < b[0];
	});
	vector<bool> visited(n, false);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (visited[i])continue;
		dfs(A, n, i + 1, A[i][1], visited);
		++res;
	}
	return res;
}
