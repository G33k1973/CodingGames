void printBoundary(Node *root)
{
	//Your code here
	if (root == NULL)return;
	std::map<int, vector<Node*>> hs;
	typedef std::pair<Node*, int> ip;
	std::queue<ip> pile;
	pile.push({ root,0 });
	std::stack<Node*> rbound;
	std::unordered_set<Node*> memo;
	std::queue<Node*> lbound;
	lbound.push(root);
	memo.insert(root);
	while (!pile.empty()) {
		int n = static_cast<int>(pile.size());
		int cl = 0;
		int cr = 0;
		for (int i = 0; i < n; ++i) {
			ip curr = pile.front();
			int level = curr.second;
			Node * r = curr.first;
			pile.pop();
			if (r->left != 0) {
				pile.push({ r->left,level - 1 });
				if (i==0) {
					if (memo.count(r->left) == 0) {
						++cl;
						lbound.push(r->left);
						memo.insert(r->left);
					}
				}
			}
			if (r->right != 0) {
				pile.push({ r->right,level + 1 });
				if (i == (n - 1)) {
					if (memo.count(r->right) == 0) {
						++cr;
						rbound.push(r->right);
						memo.insert(r->right);
					}
				}
			}
			if (r->right == 0 && r->left == 0 && memo.count(r) == 0) {
				hs[level].push_back(r);
				memo.insert(r);
			}
			if (cl == 0 && cr==0 && i == 0 && r->right != 0 && memo.count(r->right) == 0) {
				lbound.push(r->right);
				memo.insert(r->right);
			}
			if (cl == 0 && cr == 0 && i == (n-1) && r->left != 0 && memo.count(r->left) == 0) {
				rbound.push(r->left);
				memo.insert(r->left);
			}
		}
	}
	while (!lbound.empty()) {
		Node * r = lbound.front();
		lbound.pop();
		cout << r->data << " ";
	}
	for (const auto& x : hs) {
		for (const auto& y : x.second)
			cout << y->data << " ";
	}
	while (!rbound.empty()) {
		Node * temp = rbound.top();
		cout << temp->data << " ";
		rbound.pop();
	}
	return;
}