#define pb push_back
vector<int> Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return vector<int>{};
	int m = int(A.front().size());
	if (m == 0)return vector<int>{};
	if (n < 2)return vector<int>{};
	map<vector<int>, int> h;
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		if (h.find(A[i]) == end(h)) {
			++h[A[i]];
		}
		else res.pb(i + 1);
	}
	return res;
}
