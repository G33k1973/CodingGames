vector<int> Solution::dNums(vector<int> &A, int B) {
	int n = static_cast<int>(A.size());
	if (B > n || n == 0)return vector<int>{};
	unordered_map<int, int> h;
	for (int i = 0; i < B; ++i) {
		++h[A[i]];
	}
	vector<int> res;
	res.push_back(int(h.size()));
	for (int i = B; i < n; ++i) {
		int x = A[i - B];
		--h[x];
		if (h[x] == 0)h.erase(x);
		int y = A[i];
		++h[y];
		res.push_back(int(h.size()));
	}
	return res;
}