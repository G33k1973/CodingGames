/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (root == 0)return false;
		std::queue<TreeNode*> pile;
		pile.push(root);
		while (!pile.empty())
		{
			int sz = static_cast<int>(pile.size());
			int i = 0;
			TreeNode * px = 0, *py = 0;
			while (i < sz) {
				TreeNode * current = pile.front();
				pile.pop();
				if (current->left) {
					if (current->left->val == x) {
						px = current->left;
					}
					if (current->left->val == y) {
						py = current->left;
					}
					pile.push(current->left);
				}
				if (current->right) {
					if (current->right->val == x) {
						px = current->right;
					}
					if (current->right->val == y) {
						py = current->right;
					}
					pile.push(current->right);
				}
				++i;
			}
			if (px&&py&&px != py)return 1;
		}
		return 0;
	}
};