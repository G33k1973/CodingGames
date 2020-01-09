/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(vector<int>& a, int s, int e, int x) {
	int i;
	for (i = s; i <= e; ++i) {
		if (a[i] == x)break;
	}
	return i;
}
TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& pre, int& j) {
	if (is > ie)return NULL;
	TreeNode * temp = new TreeNode(pre.at(j));
	++j;
	if (is == ie || j == int(pre.size()))return temp;
	int index = search(inorder, is, ie, temp->val);
	temp->left = build(inorder, is, index - 1, pre, j);
	temp->right = build(inorder, index + 1, ie, pre, j);
	return temp;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
	int n = int(A.size());
	if (n == 0)return NULL;
	if (n == 1)return new TreeNode(A[0]);
	int j = 0;
	return build(B, 0, n - 1, A, j);
}
