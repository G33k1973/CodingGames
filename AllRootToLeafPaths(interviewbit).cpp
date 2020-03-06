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
vector<vector<int>> res;
void dfs(TreeNode * r, vector<int>& a) {
	if (r == 0)return;
	if (r->left == 0 && r->right == 0) {
		a.pb(r->val);
		res.pb(a);
		a.pop_back();
		return;
	}
	a.pb(r->val);
	dfs(r->left, a);
	dfs(r->right, a);
	a.pop_back();
}
vector<vector<int> > Solution::solve(TreeNode* A) {
	if (res.size() > 0)res.clear();
	if (A == 0)return res;
	vector<int> a;
	dfs(A, a);
	return res;
}
