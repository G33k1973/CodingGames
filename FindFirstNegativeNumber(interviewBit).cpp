vector<int> Solution::solve(vector<int> &A, int B) {
	int n = int(A.size());
	if (n == 0)return vector<int>{};
	B = min(B, n);
	map<int, int> h;
	for (int i = 0; i < B; ++i) {
		if (A[i] < 0)h.insert(make_pair(i, A[i]));
	}
	vector<int> res;
	if (h.empty())res.push_back(0);
	else res.push_back(A[begin(h)->first]);
	for (int i = B; i < n; ++i) {
		int j = i - B;
		auto it = h.find(j);
		if (it != end(h))it = h.erase(it);
		if (A[i] < 0)h.insert(make_pair(i, A[i]));
		if (h.empty())res.push_back(0);
		else res.push_back(A[begin(h)->first]);
	}
	return res;
}
