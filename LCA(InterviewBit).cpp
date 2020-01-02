/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void search(TreeNode * r, int B, int C, int& d) {
	if (r != 0) {
		if (r->val == B)++d;
		if (r->val == C)++d;
		if (d == 2)return;
		search(r->left, B, C, d);
		if (d == 2)return;
		search(r->right, B, C, d);
		if (d == 2)return;
	}
	return;
}
void dfs(TreeNode * root, int B, int C, TreeNode*&z) {
	if (root == 0)return;
	int cnt(0);
	search(root, B, C, cnt);
	if (cnt == 2)z = root;
	dfs(root->left, B, C, z);
	dfs(root->right, B, C, z);
	return;
}
int Solution::lca(TreeNode* A, int B, int C) {
	if (A == 0)return -1;
	TreeNode* z = 0;
	dfs(A, B, C, z);
	if (z == 0)return -1;
	return z->val;
}