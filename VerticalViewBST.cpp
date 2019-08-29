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
	map<int, map<int, vector<int>, less<int>>> memo;
	void dfs(TreeNode* r, int h, int l) {
		if (r == 0)return;
		memo[h][l].push_back(r->val);
		dfs(r->left, h - 1, l + 1);
		dfs(r->right, h + 1, l + 1);
		return;
	}
public:
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)return res;
		dfs(root, 0, 0);
		for (auto& x : memo) {
			vector<int> temp;
			for (auto& y : x.second) {
				temp.insert(end(temp), begin(y.second), end(y.second));
			}
			res.push_back(temp);
		}
		return res;
	}
};