/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool AreSame(TreeNode * r1, TreeNode * r2, int& sz) {
	if (r1 == 0 && r2 == 0)return 1;
	if (r1 == 0 || r2 == 0)return 0;
	if (r1->val != r2->val)return 0;
	++sz;
	return AreSame(r1->left, r2->left, sz) && AreSame(r1->right, r2->right, sz);
}
bool ans;
void dfs2(TreeNode * b, TreeNode * a, int& c) {
	if (b == 0)return;
	int sz = 0;
	if (AreSame(b, a, sz))++c;
	if (c == 2 && sz >= 2)ans = true;
	if (ans)return;
	dfs2(b->left, a, c);
	if (ans)return;
	dfs2(b->right, a, c);
	if (ans)return;
}
void dfs(TreeNode * a, TreeNode * root) {
	if (a == 0)return;
	int c = 0;
	dfs2(root, a, c);
	if (ans)return;
	dfs(a->left, root);
	if (ans)return;
	dfs(a->right, root);
	if (ans)return;
}
int Solution::solve(TreeNode* A) {
	if (A == 0)return 0;
	ans = false;
	dfs(A, A);
	//dfs(A->right,A);
	return int(ans);
}
