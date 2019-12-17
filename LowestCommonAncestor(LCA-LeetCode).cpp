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
	bool search(TreeNode*r, TreeNode*p, TreeNode*q, int& c) {
		if (r == 0)return false;
		if (r == p)++c;
		if (r == q)++c;
		if (c == 2)return true;
		return search(r->left, p, q, c) || search(r->right, p, q, c);
	}
	void dfs(TreeNode* r, TreeNode * p, TreeNode * q, TreeNode*& z) {
		if (r != NULL) {
			int c = 0;
			if (search(r, p, q, c))z = r;
			dfs(r->left, p, q, z);
			dfs(r->right, p, q, z);
		}
		return;
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == 0)return NULL;
		TreeNode * z = NULL;
		dfs(root, p, q, z);
		return z;
	}
};