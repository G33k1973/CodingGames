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
vector<int> a, b;
void dfs(TreeNode * A) {
	if (A != 0) {
		dfs(A->left);
		a.pb(A->val);
		b.pb(A->val);
		dfs(A->right);
	}
}
vector<int> Solution::recoverTree(TreeNode* A) {
	vector<int> sol;
	if (A == 0)return vector<int>{};
	if (a.size() > 0)a.clear();
	if (b.size() > 0)b.clear();
	dfs(A);
	sort(begin(b), end(b));
	int i = 0, n = int(b.size());
	if (n == 1)return vector<int>{};
	int j = 0;
	while (i < n) {
		if (a[i] != b[i]) {
			sol.pb(b[i]);
			++j;
			if (j == 2)break;
		}
		++i;
	}
	return sol;
}