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
protected:
	vector<int> arr;
	void dfs(TreeNode * r) {
		if (r != NULL) {
			dfs(r->left);
			arr.pb(r->val);
			dfs(r->right);
		}
	}
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL)return true;
		dfs(root);
		vector<int> arr2(arr.begin(), arr.end());
		sort(begin(arr2), end(arr2));
		auto it = std::unique(begin(arr2), end(arr2));
		arr2.resize(static_cast<int>(it - begin(arr2)));
		return arr == arr2;
	}
};