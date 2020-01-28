class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int i1 = -1, i2 = -1, res = INT_MAX;
		int n = int(words.size());
		int i = 0;
		while (i < n) {
			if (words[i].compare(word1) == 0) {
				if (i2 != -1)res = min(res, i - i2);
				i1 = i;
			}
			if (words[i].compare(word2) == 0) {
				if (i1 != -1)res = min(res, i - i1);
				i2 = i;
			}
			++i;
		}
		return res;
	}
};

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
	int res;
	void path(TreeNode * r, int sum,int sub) {
		if (r == 0)return;
		if (sub + r->val == sum)++res;
		path(r->left, sum, sub + r->val);
		path(r->right, sum, sub + r->val);
		return;
	}
	void dfs(TreeNode* r, int sum) {
		if (r != NULL) {
			path(r, sum, 0);
			dfs(r->left, sum);
			dfs(r->right, sum);
		}
	}
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == 0) {
			if (sum == 0)return 1;
			return 0;
		}
		res = 0;
		dfs(root, sum);
		return res;
	}
};