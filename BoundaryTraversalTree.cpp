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
	while (!pile.empty()) {
		int n = static_cast<int>(pile.size());
		int c = 0;
		for (int i = 0; i < n; ++i) {
			ip curr = pile.front();
			int level = curr.second;
			Node * r = curr.first;
			if (i == 0) {
				cout << r->data << " ";
				memo.insert(r);
			}
			pile.pop();
			if (r->left != 0) {
				++c;
				pile.push({ r->left,level - 1 });
				if (c>1 && i == (n - 1) && r->right == 0) {
					rbound.push(r->left);
					memo.insert(r->left);
				}
			}
			if (r->right != 0) {
				++c;
				pile.push({ r->right,level + 1 });
				if (c > 1 && i == (n - 1)) {
					rbound.push(r->right);
					memo.insert(r->right);
				}
			}
			if (r->right == 0 && r->left == 0 && memo.count(r)==0)hs[level].push_back(r);
		}
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