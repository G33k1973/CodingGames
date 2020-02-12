int Solution::solve(TreeNode* A, int B, int C) {
	unordered_map<int, vector<int>> graph;
	queue<TreeNode *> pile;
	pile.push(A);
	int n = 0;
	while (!pile.empty()) {
		int sz = int(pile.size());
		int i = 0;
		while (i < sz) {
			TreeNode * parent = pile.front();
			++n;
			pile.pop();
			if (parent->left) {
				graph[parent->left->val].push_back(parent->val);
				graph[parent->val].push_back(parent->left->val);
				pile.push(parent->left);
			}
			if (parent->right) {
				graph[parent->right->val].push_back(parent->val);
				graph[parent->val].push_back(parent->right->val);
				pile.push(parent->right);
			}
			++i;
		}
	}
	unordered_set<int> visited;
	visited.insert(B);
	queue<pair<int, int>> p2;
	p2.push(make_pair(B, 0));
	while (!p2.empty()) {
		int sz = int(p2.size());
		int i = 0;
		while (i < sz) {
			pair<int, int> cur = p2.front();
			p2.pop();
			int node = cur.first;
			int dist = cur.second;
			if (node == C)return dist;
			for (auto& x : graph[node]) {
				if (visited.count(x) == 0) {
					visited.insert(x);
					p2.push(make_pair(x, dist + 1));
				}
			}
			++i;
		}
	}
	return -1;

}
