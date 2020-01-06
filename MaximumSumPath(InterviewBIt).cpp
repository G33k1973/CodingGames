/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs2(TreeNode *r, int sum, int& maxsum) {
	if (r != 0) {
		maxsum = max(maxsum, sum + r->val);
		dfs2(r->left, sum + r->val, maxsum);
		dfs2(r->right, sum + r->val, maxsum);
	}
}
void dfs(TreeNode * r, int& maxsum) {
	if (r != 0) {
		int fl = INT_MIN, fr = INT_MIN;
		dfs2(r->left, 0, fl);
		dfs2(r->right, 0, fr);
		if (fl != INT_MIN && fr != INT_MIN) {
			int sub1 = r->val, sub2 = r->val + fl, sub3 = r->val + fr, sub4 = r->val + fl + fr, sub5 = fl, sub6 = fr;
			maxsum = max(maxsum, max(max(sub1, sub6), max(max(sub2, sub3), max(sub4, sub5))));
		}
		else if (fl == INT_MIN && fr != INT_MIN) {
			maxsum = max(maxsum, max(max(r->val, r->val + fr), fr));
		}
		else if (fr == INT_MIN && fl != INT_MIN) {
			maxsum = max(maxsum, max(max(r->val, r->val + fl), fl));
		}
		else maxsum = max(maxsum, r->val);
		dfs(r->left, maxsum);
		dfs(r->right, maxsum);
	}
	return;
}
int Solution::maxPathSum(TreeNode* A) {
	if (A == 0)return 0;
	int res = INT_MIN;
	dfs(A, res);
	return res;
}
