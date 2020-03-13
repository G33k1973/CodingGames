int Solution::maxSum(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return A[0];
	std::set<int, greater<int>> dig[10];
	unordered_map<int, unordered_set<int>> h;
	for (int& i : A) {
		int j(i);
		if (j == 0)continue;
		while (j) {
			int rem = j % 10;
			h[i].insert(rem);
			dig[rem].insert(i);
			j /= 10;
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int sub = A[i];
		unordered_set<int> bad(h[A[i]].begin(), h[A[i]].end());
		while (1) {
			bool suc = false;
			pair<int, int> bst{ INT_MIN,-1 };
			for (int j = 0; j < 10; ++j) {
				if (bad.count(j) > 0 || dig[j].empty())continue;
				auto ptr = dig[j].begin();
				while (ptr != dig[j].end()) {
					int posnext = *ptr++;
					bool good = true;
					for (auto& z : h[posnext]) {
						if (bad.count(z) > 0) {
							good = false;
							break;
						}
					}
					if (good&&posnext > bst.first) {
						bst = make_pair(posnext, j);
					}
					if (good) {
						if (suc == false)suc = true;
						break;
					}
				}
			}
			if (suc == false)break;
			sub += bst.first;
			for (auto& x : h[bst.first])bad.insert(x);
		}
		res = max(res, sub);
	}
	return res;
}
