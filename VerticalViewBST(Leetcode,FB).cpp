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
#define mp make_pair
class Solution {
protected:
	vector<vector<int>> r;
	map<int, vector<int>> rbt;
	using ip = pair<TreeNode*, int>;
public:
	vector<vector<int>> verticalOrder(TreeNode* root) {
		if (root == 0)return r;
		std::queue<ip> pile;
		pile.push(mp(root, 0));
		while (!pile.empty()) {
			int sz = int(pile.size());
			int u = 0;
			while (u < sz) {
				ip current = pile.front();
				pile.pop();
				TreeNode * c = current.first;
				int level = current.second;
				rbt[level].pb(c->val);
				if (c->left) {
					pile.push(mp(c->left, level - 1));
				}
				if (c->right) {
					pile.push(mp(c->right, level + 1));
				}
				++u;
			}
		}
		std::map<int, vector<int>>::iterator ptr = rbt.begin();
		while (ptr != rbt.end()) {
			r.pb(ptr->second);
			++ptr;
		}
		return r;
	}
};