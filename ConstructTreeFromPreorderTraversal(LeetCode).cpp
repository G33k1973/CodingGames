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
protected:
	TreeNode * build(vector<int>& a, int& i, int low, int high, int n) {
		if (i == n || low > high)return NULL;
		TreeNode * root = new TreeNode(a[i]);
		++i;
		if (i == n || low == high)return root;
		int j = 0;
		for (j = low; j <= high; ++j) {
			if (a[j] > root->val)break;
		}
		root->left = build(a, i, i, j - 1, n);
		root->right = build(a, i, j, high, n);
		return root;
	}
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int n = int(preorder.size());
		int i = 0;
		return build(preorder, i, 0, n - 1, n);
	}
};