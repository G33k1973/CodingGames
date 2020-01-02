/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#define pb push_back
void Solution::connect(TreeLinkNode* A) {
	if (A == 0)return;
	std::queue<TreeLinkNode*> pile;
	pile.push(A);
	while (!pile.empty()) {
		int sz = int(pile.size());
		int i = 0;
		vector<TreeLinkNode*> temp;
		while (i < sz) {
			TreeLinkNode * current = pile.front();
			pile.pop();
			temp.pb(current);
			if (current->left)pile.push(current->left);
			if (current->right)pile.push(current->right);
			++i;
		}
		i = 0;
		while (i < sz - 1) {
			temp[i]->next = temp[i + 1];
			++i;
		}
		temp.back()->next = 0;
	}
	return;
}