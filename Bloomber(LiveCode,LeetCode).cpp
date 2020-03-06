class Solution {
private:
	vector<vector<bool>> visited;
	int n, m, res;
	int dfs(const vector<vector<int>>& grid, int i, int j) {
		visited[i][j] = true;
		int ans = 1;
		static int X[4] = { 1,-1,0,0 };
		static int Y[4] = { 0,0,-1,+1 };
		for (int k = 0; k < 4; ++k) {
			int ni = i + X[k];
			int nj = j + Y[k];
			if (ni >= 0 && ni < n&&nj >= 0 && nj < m && !visited[ni][nj] && grid[ni][nj] == 1) {
				ans += dfs(grid, ni, nj);
			}
		}
		return ans;
	}
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		this->n = static_cast<int>(grid.size());
		if (n == 0)return 0;
		this->m = static_cast<int>(grid.front().size());
		if (m == 0)return 0;
		visited.assign(n, vector<bool>(m, false));
		res = 0;
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (!visited[i][j] && grid[i][j] == 1) {
					int sub = dfs(grid, i, j);
					res = max(res, sub);
				}
			}
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
private:
	int res;
	bool isgood(TreeNode * r, int x) {
		if (r == 0)return 1;
		if (r->val != x)return false;
		return isgood(r->left, x) && isgood(r->right, x);
	}
	void dfs(TreeNode* r) {
		if (r != 0) {
			if (isgood(r, r->val))++res;
			dfs(r->left);
			dfs(r->right);
		}
		return;
	}
public:
	int countUnivalSubtrees(TreeNode* root) {
		if (root == 0)return 0;
		res = 0;
		dfs(root);
		return res;
	}
};