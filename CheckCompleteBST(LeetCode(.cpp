/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using ll = unsigned long long int;
using lp = std::pair<TreeNode*, ll>;
class Solution {
private:
public:
	bool isCompleteTree(TreeNode* root) {
		if (root == 0)return true;
		ll level = 0;
		std::queue<lp> pile;
		pile.push(make_pair(root, 0ULL));
		while (!pile.empty()) {
			int sz = static_cast<int>(pile.size());
			int i = 0;
			ll tofind = (1ULL << level);
			ll cnt = 0ULL;
			ll nxt = (level == 0) ? (0) : ((1ULL << (level)) - 1);
			while (i < sz) {
				lp current = pile.front();
				pile.pop();
				TreeNode * c = current.first;
				ll ix = current.second;
				if (ix != nxt)return false;
				if (c->left != 0) {
					pile.push(make_pair(c->left, 2ULL * ix + 1ULL));
				}
				if (c->right != 0) {
					pile.push(make_pair(c->right, 2ULL * ix + 2ULL));
				}
				++nxt;
				++cnt;
				++i;
			}
			if (cnt != tofind) {
				return pile.empty();
			}
			++level;
		}
		return true;
	}
};