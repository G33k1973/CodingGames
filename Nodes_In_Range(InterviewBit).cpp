/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A, int B, int C) {
	if (A == 0)return 0;
	if (A->val < B)return solve(A->right, B, C);
	else if (A->val > C)return solve(A->left, B, C);
	else return 1 + solve(A->left, B, C) + solve(A->right, B, C);
}
