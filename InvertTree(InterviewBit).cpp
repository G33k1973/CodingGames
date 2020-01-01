/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
	if (A == 0)return 0;
	queue<TreeNode*> pile;
	pile.push(A);
	while (!pile.empty()) {
		int sz = int(pile.size());
		int i = 0;
		while (i < sz) {
			TreeNode * current = pile.front();
			pile.pop();
			swap(current->left, current->right);
			if (current->left)pile.push(current->left);
			if (current->right)pile.push(current->right);
			++i;
		}
	}
	return A;
}
