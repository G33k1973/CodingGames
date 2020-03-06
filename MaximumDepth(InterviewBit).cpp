vector<int> Solution::solve(int A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E, vector<int> &F) {
	int n = static_cast<int>(B.size());
	int n2 = static_cast<int>(C.size());
	assert(n == n2);
	int q = int(E.size());
	if (A == 0)return vector<int>(q, -1);
	unordered_map<int, vector<int>> graph;
	for (int i = 0; i < n; ++i) {
		int u = B[i], v = C[i];
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	unordered_set<int> seen;
	unordered_map<int, set<int>> levset;
	int mxdepth = 0;
	queue<int> pile;
	pile.push(0);
	seen.insert(0);
	int level = -1;
	while (!pile.empty()) {
		int sz = int(pile.size());
		int i = 0;
		++level;
		while (i < sz) {
			int node = pile.front();
			pile.pop();
			levset[level].insert(D[node]);
			for (int& y : graph[node]) {
				if (seen.count(y) == 0) {
					seen.insert(y);
					pile.push(y);
				}
			}
			++i;
		}
	}
	mxdepth = level;
	++mxdepth;
	vector<int> result;
	for (int i = 0; i < q; ++i) {
		int lev = E[i], x = F[i];
		lev %= mxdepth;
		auto it = levset.find(lev);
		if (it == end(levset)) {
			result.push_back(-1);
			continue;
		}
		auto it2 = it->second.lower_bound(x);
		if (it2 == end(it->second)) {
			result.push_back(-1);
			continue;
		}
		result.push_back(*it2);
	}
	return result;
}
