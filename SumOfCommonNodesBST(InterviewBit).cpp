/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
void dfs(TreeNode * root, vector<int>& a) {
	if (root == 0)return;
	dfs(root->left, a);
	a.pb(root->val);
	dfs(root->right, a);
	return;
}
int Solution::solve(TreeNode* A, TreeNode* B) {
	if (A == 0 || B == 0)return 0;
	vector<int> a, b;
	dfs(A, a);
	dfs(B, b);
	int n = int(a.size());
	int m = int(b.size());
	int i = 0, j = 0;
	int res{ 0 };
	while (i < n&&j < m) {
		if (a[i] < b[j]) {
			++i;
		}
		else if (a[i] > b[j]) {
			++j;
		}
		else {
			res += a[i];
			++i, ++j;
		}
	}
	return res;
}
