/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
class Solution {
protected:
	int dfs(TreeNode* r, int prev, int& incr) {
		if (r == 0)return 0;
		int x = r->val;
		if (incr == -1) {
			if (abs(x - prev) != 1)return 0;
			if (x > prev) {
				incr = 1;
			}
			else {
				incr = 0;
			}
		}
		if (incr == 0) {
			if (x + 1 != prev)return 0;
			else return 1 + max(dfs(r->left, x, incr), dfs(r->right, x, incr));
		}
		if ((x - 1) != prev)return 0;
		return 1 + max(dfs(r->left, x, incr), dfs(r->right, x, incr));
	}
	void dfs(TreeNode * r, int& ans) {
		if (r == 0)return;
		int incrR = -1, incrL = -1;
		int fR = dfs(r->right, r->val, incrR);
		int fL = dfs(r->left, r->val, incrL);
		int sub(1);
		if (incrR^incrL)sub += fL + fR;
		else sub += max(fL, fR);
		ans = max(ans, sub);
		dfs(r->left, ans);
		dfs(r->right, ans);
		return;
	}
public:
	int longestConsecutive(TreeNode* root) {
		if (root == 0)return 0;
		int res(0);
		(*this).dfs(root, res);
		return res;
	}
};