/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};
*/
class Solution {
public:
	Node* connect(Node* root) {
		if (root == 0)return root;
		std::queue<Node*> pile;
		pile.push(root);
		while (!pile.empty()) {
			vector<Node*> temp;
			int sz = static_cast<int>(pile.size());
			int i(0);
			while (i < sz) {
				Node * cur = pile.front();
				pile.pop();
				temp.push_back(cur);
				if (cur->left)pile.push((*cur).left);
				if (cur->right)pile.push((*cur).right);
				++i;
			}
			int n = (int)temp.size();
			i = 0;
			while (i < n) {
				Node * r = temp.at(i);
				if (i == (n - 1)) {
					r->next = 0;
					break;
				}
				r->next = temp.at(i + 1);
				++i;
			}
		}
		return root;
	}
};