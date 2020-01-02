/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define M 1003
int Get(string& s) {
	int res = 0;
	int l = int(s.size());
	for (auto& x : s) {
		res = (res * 10 + (x - '0') % M) % M;
	}
	return res;
}
#define ms(a,b) (((a%M)+(b%M))%M)
int tot;
void dfs(TreeNode * a, string& s) {
	if (a == 0)return;
	if (a->left == 0 && a->right == 0) {
		s += string(1, a->val + '0');
		tot = ms(tot, Get(s));
		s.pop_back();
		return;
	}
	s.push_back(a->val + '0');
	dfs(a->left, s);
	dfs(a->right, s);
	s.pop_back();
	return;
}
int Solution::sumNumbers(TreeNode* A) {
	if (A == 0)return 0;
	tot = 0;
	string s("");
	dfs(A, s);
	return tot;
}
