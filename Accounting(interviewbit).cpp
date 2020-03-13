int Solution::countMismatchedPayments(vector<string> &A, vector<int> &B, vector<string> &C, vector<int> &D) {
	int n = int(A.size());
	if (n == 0)return 0;
	assert(A.size() == B.size());
	unordered_map<string, unordered_map<int, int>> dict;
	for (int i = 0; i < n; ++i) {
		dict[A[i]][B[i]]++;
	}
	assert(C.size() == D.size());
	if (C.size() == 0)return 0;
	int res = 0;
	for (int j = 0; j<int(C.size()); ++j) {
		string name = C[j];
		auto it = dict.find(name);
		if (it == end(dict))continue;
		int amount = D[j];
		auto it2 = it->second.find(amount);
		if (it2 != end(it->second)) {
			++res;
			--it2->second;
			if (it2->second == 0)it->second.erase(amount);
		}
		if (it->second.empty())dict.erase(name);
	}
	return int(C.size()) - res;
}
