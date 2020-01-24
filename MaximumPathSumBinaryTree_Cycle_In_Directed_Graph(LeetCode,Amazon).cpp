class Solution {
protected:
	enum col { WHITE, GRAY, BLACK };
	std::unordered_map<int, vector<int>> graph;
	vector<col> color;
	int tot;
	bool isCyclic(int src) {
		color.at(src) = GRAY;
		for (auto& x : graph[src]) {
			if (color[x] == WHITE && isCyclic(x))return true;
			if (color[x] == GRAY)return true;
		}
		color.at(src) = BLACK;
		++tot;
		return false;
	}
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses < 2)return true;
		vector<bool> isroot(numCourses, true);
		for (auto& x : prerequisites) {
			int u = x.back(), v = x.front();
			if (u == v)continue;
			if (isroot[v] == true) {
				isroot[v] = false;
			}
			graph[u].push_back(v);
		}
		tot = 0;
		color.assign(numCourses, WHITE);
		for (int i = 0; i < numCourses; ++i) {
			if (color[i] == WHITE && isroot.at(i)) {
				if (isCyclic(i))return false;
			}
		}
		return tot == numCourses;
	}
};
#define pb push_back
class Solution {
private:
	enum col { WHITE, GRAY, BLACK };
	vector<int> result;
	std::unordered_map<int, vector<int>> graph;
	vector<col> color;
	int tot;
	bool isCyclic(int src) {
		color.at(src) = GRAY;
		for (auto& x : graph[src]) {
			if (color[x] == WHITE && isCyclic(x))return true;
			if (color[x] == GRAY)return true;
		}
		color.at(src) = BLACK;
		++tot;
		result.pb(src);
		return false;
	}
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses < 2) {
			if (numCourses == 0)return vector<int>{};
			return vector<int>{0};
		}
		vector<bool> isroot(numCourses, true);
		for (auto& x : prerequisites) {
			int v = x.back(), u = x.front();
			if (u == v)continue;
			if (isroot[v] == true) {
				isroot[v] = false;
			}
			graph[u].push_back(v);
		}
		tot = 0;
		color.assign(numCourses, WHITE);
		for (int i = 0; i < numCourses; ++i) {
			if (color[i] == WHITE && isroot.at(i)) {
				if (isCyclic(i))return vector<int>{};
			}
		}
		if (tot != numCourses) {
			return vector<int>{};
		}
		return result;
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
	void GetMaxSum(TreeNode * root, int current, int& best) {
		if (root == 0) {
			return;
		}
		best = max(best, current + root->val);
		GetMaxSum(root->left, current + root->val, best);
		GetMaxSum(root->right, current + root->val, best);
		return;
	}
	void dfs(TreeNode* root) {
		if (root != NULL) {
			int fl = INT_MIN;
			int fr = INT_MIN;
			GetMaxSum(root->left, 0, fl);
			GetMaxSum(root->right, 0, fr);
			if (fl == INT_MIN && fr == INT_MIN) {
				res = max(res, root->val);
			}
			else if (fl == INT_MIN) {
				if (fr > 0)res = max(res, max(root->val, root->val + fr));
				else res = max(res, root->val);
			}
			else if (fr == INT_MIN) {
				if (fl > 0)res = max(res, max(root->val, root->val + fl));
				else res = max(res, root->val);
			}
			else {
				fl = max(0, fl);
				fr = max(0, fr);
				int pathsum1 = root->val;
				int pathsum2 = root->val + fl;
				int pathsum3 = root->val + fr;
				int pathsum4 = root->val + fl + fr;
				res = max(res, max(max(pathsum1, pathsum2), max(pathsum3, pathsum4)));
			}
			dfs(root->left);
			dfs(root->right);
		}
		return;
	}
public:
	int maxPathSum(TreeNode* root) {
		if (root == 0)return NULL;
		this->res = INT_MIN;
		dfs(root);
		return res;
	}
};