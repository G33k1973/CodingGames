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
	std::unordered_set<TreeNode*> memo;
	std::unordered_set<int> to_delete;
	std::unordered_set<TreeNode*> visited;
	vector<TreeNode*> result;
	void search(TreeNode * root) {
		if (root == 0)return;
		if (to_delete.count(root->val) > 0)memo.insert(root);
		search(root->left);
		search(root->right);
		return;
	}
	TreeNode* build(TreeNode * r, vector<TreeNode*>& sachet) {
		if (r == 0)return NULL;
		if (memo.count(r) > 0 && visited.count(r) == 0) {
			sachet.push_back(r);
			visited.insert(r);
			return NULL;
		}
		TreeNode * z = NULL;
		if (visited.count(r) == 0) {
			visited.insert(r);
			z = new TreeNode(r->val);
			z->left = build(r->left, sachet);
			z->right = build(r->right, sachet);
		}
		return z;
	}
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		if (root == 0)return result;
		for (const auto& x : to_delete) {
			this->to_delete.insert(x);
		}
		search(root);
		TreeNode * z = NULL;
		int tot = 0;
		vector<TreeNode*> sachet;
		z = build(root, sachet);
		if (z != NULL)result.push_back(z);
		vector<TreeNode*> sachet2;
		while (1) {
			for (const auto& x : sachet) {
				int tot = 0;
				TreeNode * z = NULL;
				z = build(x->left, sachet2);
				if (z != NULL)result.push_back(z);
				z = NULL;
				z = build(x->right, sachet2);
				if (z != NULL)result.push_back(z);
			}
			if (sachet2.empty())break;
			sachet = std::move(sachet2);
		}
		return result;
	}
};