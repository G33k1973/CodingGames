/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
*/
#define pb push_back
class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL)return NULL;
		std::queue<Node*> pile;
		pile.push(root);
		while (!pile.empty()) {
			int sz = static_cast<int>(pile.size());
			int i = 0;
			vector<Node*> arr;
			while (i < sz) {
				Node * curr = pile.front();
				pile.pop();
				arr.pb(curr);
				if (curr->left != 0)pile.push(curr->left);
				if (curr->right != 0)pile.push(curr->right);
				++i;
			}
			int m = int(arr.size());
			int j = 0;
			while (j < m - 1) {
				arr[j]->next = arr[j + 1];
				++j;
			}
			arr.back()->next = NULL;
		}
		return root;
	}
};