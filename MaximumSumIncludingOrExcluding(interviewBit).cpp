/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
#define sc static_cast<ll>
pair<ll, ll> GetSum(TreeNode * root) {
	if (root == 0) {
		return pair<ll, ll>(0, 0);
	}
	pair<ll, ll> sum1 = GetSum(root->left);
	pair<ll, ll> sum2 = GetSum(root->right);
	pair<ll, ll> sum;
	sum.first = ms(sc(root->val), sum1.second);
	sum.first = ms(sum.first, sum2.second);
	sum.second = ms(max(sum1.first, sum1.second), max(sum2.first, sum2.second));
	return sum;
}
int Solution::solve(TreeNode* A) {
	pair<ll, ll> ans = GetSum(A);
	return max(int(ans.first), int(ans.second));
}
