/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
	int depth;
	void dfs(NestedInteger& nint,int level) {
		if (nint.isInteger()) {
			depth = max(level, depth);
			return;
		}
		for (auto& x : nint.getList()) {
			dfs(x, level + 1);
		}
		return;
	}
	void acc(NestedInteger& nint,int level,int& res){
		if (nint.isInteger()) {
			res += level * nint.getInteger();
			return;
		}
		for (auto& x : nint.getList()) {
			acc(x, level - 1, res);
		}
	}
public:
	int depthSumInverse(vector<NestedInteger>& nestedList) {
		depth = 0;
		int n = int(nestedList.size());
		if (n == 0)return 0;
		for (auto& x : nestedList) {
			dfs(x, 0);
		}
		++depth;
		int res = 0;
		for (auto& x : nestedList) {
			acc(x, depth, res);
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
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (root == 0)return 0;
		if (root->val >= L && root->val <= R) {
			return root->val + rangeSumBST(root->left, L, R) +
				rangeSumBST(root->right, L, R);
		}
		else if (root->val < L) {
			return rangeSumBST(root->right, L, R);
		}
		return rangeSumBST(root->left, L, R);
	}
};