/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using bst = TreeNode;
class Solution {
private:
	int search(vector<int>& inorder, int n, int x) {
		int i;
		for (i = 0; i < n; ++i) {
			if (inorder[i] == x)break;
		}
		return i;
	}
	bst * build(vector<int>& ino, vector<int>& post, int low, int high, int n, int& i) {
		if (low > high)return nullptr;
		bst * root = new bst(post.operator[](i));
		--i;
		if (i < 0)return root;
		if (low == high)return root;
		int index = this->search(ino, n, root->val);
		root->right = build(ino, post, index + 1, high, n, i);
		root->left = build(ino, post, low, index - 1, n, i);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		const int n = int(inorder.size());
		const int m = int(postorder.size());
		assert(n == m);
		if (!n)return nullptr;
		if (n == 1)return new TreeNode(inorder.front());
		int u = n - 1;
		return build(inorder, postorder, 0, n - 1, n, u);
	}
};