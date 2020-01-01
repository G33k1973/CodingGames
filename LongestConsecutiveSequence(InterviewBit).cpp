int Solution::longestConsecutive(const vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return n;
	set<int> bst;
	for (auto& x : A)bst.insert(x);
	auto ptr = begin(bst);
	int res = 1;
	while (ptr != end(bst)) {
		int x = *ptr;
		int sub = 1;
		auto it = next(ptr, 1);
		while (it != end(bst) && *it == (x + 1)) {
			++x, ++it, ++sub;
		}
		res = max(res, sub);
		ptr = it;
	}
	return res;
}