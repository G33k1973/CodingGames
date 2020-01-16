int Solution::solve(const string A, const string B) {
	int l = int(A.size());
	int n = int(B.size());
	string aa(""), bb("");
	for (int i = 0; i < l; ++i) {
		if (A[i] == '\\') {
			if (aa.size() > 0)aa.pop_back();
			i++;
		}
		else aa.push_back(A[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (B[i] == '\\') {
			if (bb.size() > 0)bb.pop_back();
			i++;
		}
		else bb.push_back(B[i]);
	}
	return aa.compare(bb) == 0;
}
