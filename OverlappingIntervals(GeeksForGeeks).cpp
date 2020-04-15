#define M 1005
using ip = pair<int, int>;
void dfs(const vector<ip>& a, int n, int i, int& ts, int& te, vector<bool>& visited) {
	if (i == n)return;
	if (visited[i] || a[i].first > te)dfs(a, n, i + 1, ts, te, visited);
	else {
		ts = min(ts, a[i].first);
		te = max(te, a[i].second);
		visited[i] = 1;
		dfs(a, n, i + 1, ts, te, visited);
	}
}
vector<pair<int, int>> overlappedInterval(vector<pair<int, int>> vec, int n) {
	//code here
	if (n < 2)return vec;
	sort(begin(vec), end(vec), [&](const pair<int, int>& a, const pair<int, int>& b)->bool {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first < b.first;
	});
	vector<bool> visited(n, false);
	vector<ip> r;
	for (int i = 0; i < n; ++i) {
		if (visited[i])continue;
		int st_ = vec[i].first, ed_ = vec[i].second;
		dfs(vec, n, i + 1, st_, ed_, visited);
		r.push_back(make_pair(st_, ed_));
	}
	return r;
}