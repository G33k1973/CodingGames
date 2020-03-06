vector<int> Solution::solve(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n == 0)return vector<int>{};
	if (n == 1)return A;
	vector<int> res;
	for (int cl = 1; cl <= n; ++cl) {
		int val = INT_MIN;
		map<int, int> bst;
		for (int i = 0; i < cl; ++i) {
			++bst[A[i]];
		}
		val = begin(bst)->first;
		for (int i = cl; i < n; ++i) {
			int x = A[i - cl];
			--bst[x];
			if (bst[x] == 0)bst.erase(x);
			++bst[A[i]];
			val = max(val, bst.begin()->first);
		}
		res.push_back(val);
	}
	return res;
}
