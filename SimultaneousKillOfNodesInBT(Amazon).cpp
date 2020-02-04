/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	void compute(TreeNode * r, int current, int& best) {
		if (r == 0)return;
		if (r->left == 0 && r->right == 0) {
			best = max(best, current + r->val);
			return;
		}
		compute(r->left, current + r->val, best);
		compute(r->right, current + r->val, best);
	}
	TreeNode * build(TreeNode * r, int limit, int acc) {
		if (r == 0)return NULL;
		int best = INT_MIN;
		compute(r, acc, best);
		if (best < limit)return NULL;
		r->left = build(r->left, limit, acc + r->val);
		r->right = build(r->right, limit, acc + r->val);
		return r;
	}
public:
	TreeNode* sufficientSubset(TreeNode* root, int limit) {
		if (root == 0)return nullptr;
		return build(root, limit, 0);
	}
};