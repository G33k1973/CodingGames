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
protected:
	int res;
	int maxnodes(TreeNode * r) {
		if (r == 0)return 0;
		return 1 + max(maxnodes(r->left), maxnodes(r->right));
	}
	void dfs(TreeNode *r) {
		if (r != 0) {
			int fl = maxnodes(r->left);
			int fr = maxnodes(r->right);
			int& ans = res;
			ans = max(ans, fl + fr);
			dfs(r->left);
			dfs(r->right);
		}
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == 0)return 0;
		res = 0;
		dfs(root);
		return res;
	}
};