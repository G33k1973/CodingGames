/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(vector<int>& inorder, int is, int ie, int x) {
	int index = -1;
	for (int i = is; i <= ie; ++i) {
		if (inorder[i] == x) {
			index = i;
			break;
		}
	}
	return index;
}
TreeNode * build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int& j) {
	if (is > ie)return 0;
	TreeNode * temp = new TreeNode(postorder.at(j));
	--j;
	if (is == ie)return temp;
	int index = search(inorder, is, ie, temp->val);
	temp->right = build(inorder, index + 1, ie, postorder, j);
	temp->left = build(inorder, is, index - 1, postorder, j);
	return temp;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(B.size());
	assert(m == n);
	if (n == 1)return new TreeNode(A.front());
	int j = n - 1;
	return build(A, 0, n - 1, B, j);
}
