/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int tot;
int target;
int n;
void dfs(TreeNode * root) {
	if (root != 0) {
		tot += root->val;
		++n;
		dfs(root->left);
		dfs(root->right);
	}
}
int acc(TreeNode * root) {
	if (root == 0)return 0;
	return root->val + acc(root->left) + acc(root->right);
}
void dfs(TreeNode * root, bool& suc) {
	if (root != 0) {
		if (root->left) {
			int fl = acc(root->left);
			int rem = tot - fl;
			if (rem == fl) {
				suc = 1;
				return;
			}
		}
		if (root->right) {
			int fr = acc(root->right);
			int rem = tot - fr;
			if (rem == fr) {
				suc = 1;
				return;
			}
		}
		dfs(root->left, suc);
		if (suc == true)return;
		dfs(root->right, suc);
		if (suc == true)return;
	}
}
int Solution::solve(TreeNode* A) {
	if (A == 0)return 0;
	tot = 0;
	n = 0;
	dfs(A);
	bool neg = false;
	/*
	if(tot<0)neg=!neg;
	if(neg)tot=-tot;
	if(tot&1)return 0;
	if(neg)tot=-tot;
	*/
	bool suc = false;
	dfs(A, suc);
	return int(suc);
}
