/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int dfs(TreeNode * root) {
	if (root == 0)return 0;
	return root->val + dfs(root->left) + dfs(root->right);
}
int Solution::solve(TreeNode* A) {
	if (A == 0)return 1;
	if (A->left == 0 && A->right == 0)return 1;
	int x = A->val;
	TreeNode * root = A;
	int y = dfs(root->left) + dfs(root->right);
	if (y != x)return 0;
	return solve(A->left) && solve(A->right);
}
