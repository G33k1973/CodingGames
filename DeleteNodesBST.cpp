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
	unordered_set<int> visited, del;
	void build(TreeNode * root, TreeNode* & z, int& c) {
		if (root == 0)return;
		if (del.count(root->val) > 0) {
			if (c > 0)return;
			build(root->left, z, c);
			if (c > 0)return;
			build(root->right, z, c);
		}
		else if (visited.count(root->val) > 0) {
			build(root->left, z, c);
			if (c > 0)return;
			build(root->right, z, c);
		}
		else {
			visited.insert(root->val);
			z = new TreeNode(root->val);
			++c;
			build(root->left, z->left, c);
			build(root->right, z->right, c);
		}
		return;
	}
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		if (root == 0)return vector<TreeNode*>{};
		for (int& i : to_delete)del.insert(i);
		vector<TreeNode*> result;
		do {
			int c = 0;
			TreeNode * z = 0;
			build(root, z, c);
			cout << c << endl;
			if (c == 0)break;
			if (z)result.push_back(z);
		} while (1);
		return result;
	}
};