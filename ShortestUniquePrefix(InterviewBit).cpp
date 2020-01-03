#define pb push_back
vector<string> sol;
vector<string> Solution::prefix(vector<string> &A) {
	int l = static_cast<int>(A.size());
	if (sol.empty() ^ 1)sol.clear();
	if (l == 0)return sol;
	if (l == 1)return vector<string>{ {string(1, A.front().front())}};
	std::unordered_map<char, set<string>> dict;
	for (auto& x : A) {
		if (x.empty())continue;
		dict[x[0]].insert(x);
	}
	for (int i = 0; i < l; ++i) {
		char fc = A[i].front();
		auto it = dict.find(fc);
		if (it->second.size() == 1) {
			sol.pb(string(1, fc));
			continue;
		}
		int n = int(A[i].length());
		string sub(1, fc);
		for (int j = 1; j < n; ++j) {
			sub.pb(A[i][j]);
			auto ptr = it->second.lower_bound(sub);
			bool suc = 1;
			while (++ptr != end(it->second)) {
				auto pos = ptr->find(sub, 0);
				if (pos == 0) {
					suc = 0;
					break;
				}
				else break;
			}
			if (suc) {
				sol.pb(sub);
				break;
			}
		}
	}
	return sol;
}
