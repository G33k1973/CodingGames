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
private:
	vector<int> arr;
	void LeftBound(TreeNode * root) {
		if (root == 0)return;
		if (root->left) {
			arr.pb(root->val);
			LeftBound(root->left);
		}
		else if (root->right) {
			arr.pb(root->val);
			LeftBound(root->right);
		}
	}
	void RightBound(TreeNode * root) {
		if (root == 0)return;
		if (root->left == 0 && root->right == 0)return;
		if (root->right) {
			RightBound(root->right);
			arr.pb(root->val);
		}
		else if (root->left) {
			RightBound(root->left);
			arr.pb(root->val);
		}
	}
	void PrintLeaves(TreeNode * r) {
		if (r == 0)return;
		PrintLeaves(r->left);
		if (r->left == 0 && r->right == 0) {
			arr.pb(r->val);
		}
		PrintLeaves(r->right);
	}
public:
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		if (root == 0)return arr;
		arr.pb(root->val);
		LeftBound(root->left);
		PrintLeaves(root->left);
		PrintLeaves(root->right);
		RightBound(root->right);
		return arr;
	}
};