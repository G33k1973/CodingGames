/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int acc(TreeNode * root, int val) {
	if (root == 0 || root->val != (val + 1))return 0;
	return 1 + max(acc(root->left, root->val), acc(root->right, root->val));
}
void dfs(TreeNode* root, int& ans) {
	if (root != 0) {
		int fl = 1 + acc(root->left, root->val);
		int fr = 1 + acc(root->right, root->val);
		ans = max(ans, max(fl, fr));
		dfs(root->left, ans);
		dfs(root->right, ans);
	}
	return;
}
int Solution::solve(TreeNode* A) {
	if (A == 0)return 0;
	int lp = 0;
	dfs(A, lp);
	return lp;
}
