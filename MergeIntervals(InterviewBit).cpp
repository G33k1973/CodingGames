/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(const Interval& a, const Interval& b) {
	if (a.start == b.start)return a.end < b.end;
	return a.start < b.start;
}
bool AreOverlapping(Interval& a, Interval& b) {
	if (a.end < b.start)return false;
	if (a.start > b.end)return false;
	return true;
}
void dfs(vector<Interval> &A, int n, int i, int& end, vector<bool>& v) {
	if (i == n)return;
	if (A[i].start > end)return;
	v[i] = true;
	end = max(end, A[i].end);
	dfs(A, n, i + 1, end, v);
	return;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = int(A.size());
	if (n < 2)return A;
	sort(begin(A), end(A), comp);
	vector<bool> visited(n, false);
	vector<Interval> res;
	for (int i = 0; i < n; ++i) {
		if (visited[i])continue;
		dfs(A, n, i + 1, A[i].end, visited);
		Interval temp(A[i].start, A[i].end);
		res.push_back(A[i]);
	}
	return res;
}