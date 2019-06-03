Node *createTree(int parent[], int n)
{
	// Your code here
	if (n == 0)return NULL;
	std::unordered_map<int, vector<int>> h;
	int i = 0;
	while (i < n) {
		h[parent[i]].push_back(i);
		++i;
	}
	typedef std::pair<Node*, int> mp;
	std::queue<mp> p;
	auto it = h.find(-1);
	Node * root = new Node(it->second[0]);
	p.push({ root,it->second[0] });
	while (!p.empty()) {
		int m = static_cast<int>(p.size());
		for (int j = 0; j < m; ++j) {
			mp c = p.front();
			p.pop();
			Node * pr = c.first;
			int val = c.second;
			auto it = h.find(val);
			if (it != end(h)) {
				int x = it->second.front();
				pr->left = new Node(x);
				p.push({ pr->left,x });
				if (it->second.size() > 1) {
					x = it->second.back();
					pr->right = new Node(x);
					p.push({ pr->right,x });
				}
			}
		}
	}
	return root;
}