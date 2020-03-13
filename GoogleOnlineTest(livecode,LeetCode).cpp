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
	void dfs(TreeNode * root, unordered_set<int>& h, unordered_set<int>& vis, TreeNode*& z, bool st) {
		if (root == 0)return;
		if (h.count(root->val) > 0) {
			if (st == false) {
				if (vis.count(root->val) == 0) {
					vis.insert(root->val);
					dfs(root->left, h, vis, z, st);
					if (z != 0)return;
					dfs(root->right, h, vis, z, st);
				}
				else {
					dfs(root->left, h, vis, z, st);
					if (z != 0)return;
					dfs(root->right, h, vis, z, st);
				}
			}
		}
		else if (vis.count(root->val) > 0) {
			dfs(root->left, h, vis, z, st);
			if (z != 0)return;
			dfs(root->right, h, vis, z, st);
		}
		else if (vis.count(root->val) == 0) {
			if (st == false)st = true;
			z = new TreeNode(root->val);
			vis.insert(root->val);
			dfs(root->left, h, vis, z->left, st);
			dfs(root->right, h, vis, z->right, st);
		}
	}
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		int n = int(to_delete.size());
		if (n == 0) {
			vector<TreeNode*> a{ root };
			return a;
		}
		vector<TreeNode*> a;
		unordered_set<int> h, visited;
		for (int i = 0; i < n; ++i)h.insert(to_delete[i]);
		while (1) {
			TreeNode * z = 0;
			bool st = 0;
			dfs(root, h, visited, z, st);
			if (z == 0)break;
			a.push_back(z);
		}
		return a;
	}
};

class Solution {
private:
	int X[8] = { 2,2,1,1,-2,-2,-1,-1 };
	int Y[8] = { -1,1,2,-2,1,-1,2,-2 };
	bool isvalid(int i, int j, int N) {
		return (i >= 0 && j >= 0 && i < N&&j < N);
	}
	vector<vector<vector<double>>> dp;
	double dfs(int N, int K, int i, int j) {
		if (K == 0)return 1.0;
		if (dp[i][j][K] != -1.)return dp[i][j][K];
		double ans = 0.0;
		int c = 0;
		for (int k = 0; k < 8; ++k) {
			int ni = i + X[k];
			int nj = j + Y[k];
			if (isvalid(ni, nj, N)) {
				ans += (1. / 8.)*dfs(N, K - 1, ni, nj);
			}
		}
		return dp[i][j][K] = ans;
	}
public:
	double knightProbability(int N, int K, int r, int c) {
		dp.assign(N, vector<vector<double>>(N, vector<double>(K + 1, -1.0)));
		return dfs(N, K, r, c);
	}
};