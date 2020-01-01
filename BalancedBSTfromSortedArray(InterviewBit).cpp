/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode * build(int low, int high, const vector<int>& a) {
	if (low > high)return NULL;
	int middle = low + (high - low) / 2;
	TreeNode * root = new TreeNode(a.at(middle));
	if (low == high)return root;
	root->left = build(low, middle - 1, a);
	root->right = build(middle + 1, high, a);
	return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
	if (A.empty())return 0;
	int l = 0, h = int(A.size()) - 1;
	return build(l, h, A);
}