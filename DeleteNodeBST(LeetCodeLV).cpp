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
class Solution {
protected:
	TreeNode* getminimum(TreeNode* root) {
		if (!root->left && !root->right)return root;
		if (root->left)return getminimum(root->left);
		return root;
	}
	TreeNode* del(TreeNode*& root, int key) {
		if (root == nullptr)return root;
		if (root->val > key)root->left = del(root->left, key);
		else if (root->val < key)root->right = del(root->right, key);
		else {
			if (!root->left && !root->right) {
				root = nullptr;
				return root;
			}
			else if (!root->left) {
				root = root->right;
			}
			else if (!root->right) {
				root = root->left;
			}
			else {
				TreeNode* temp = getminimum(root->right);
				root->val = temp->val;
				root->right = del(root->right, root->val);
			}
		}
		return root;
	}
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr)return root;
		del(root, key);
		return root;
	}
};