vector<string> Solution::solve(vector<int> &A, vector<string> &B, vector<string> &C, vector<int> &D) {
	int n = static_cast<int>(A.size());
	if (n == 0)return vector<string>{};
	unordered_map<string, map<int, string>> h;
	vector<string> result;
	for (int i = 0; i < n; ++i) {
		int op = A.at(i);
		if (op == 1) {
			h[B[i]][D[i]] = C[i];
			result.push_back("null");
		}
		else if (op == 2) {
			string k = B[i];
			auto it = h.find(k);
			if (it == end(h)) {
				result.push_back("null");
				continue;
			}
			auto it2 = it->second.lower_bound(D[i]);
			if (it2 == end(it->second)) {
				--it2;
			}
			bool tocon = false;
			while (1) {
				if (it2->first > D[i]) {
					if (it2 == begin(it->second)) {
						tocon = true;
						break;
					}
					--it2;
				}
				else {
					/*
					if (it2->second != B[i]) {
						if (it2 == begin(it->second)) {
							result.push_back("null");
							tocon = true;
							break;
						}
					}
					*/
					break;
				}
			}
			if (tocon) {
				result.push_back("null");
				continue;
			}
			result.push_back(it2->second);
		}
	}
	return result;
}
