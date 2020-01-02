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
void dfs(TreeNode * A, int pathsum, int B, vector<int>& temp) {
	if (A == 0)return;
	if (A->left == 0 && A->right == 0) {
		if (pathsum + A->val == B) {
			temp.pb(A->val);
			res.pb(temp);
			temp.pop_back();
		}
		return;
	}
	temp.pb(A->val);
	dfs(A->left, pathsum + A->val, B, temp);
	dfs(A->right, pathsum + A->val, B, temp);
	temp.pop_back();
	return;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
	if (res.size() > 0)res.clear();
	if (A == 0)return res;
	vector<int> temp{};
	dfs(A, 0, B, temp);
	return res;
}
