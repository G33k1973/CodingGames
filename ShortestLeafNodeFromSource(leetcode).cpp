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
class Solution {
protected:
	std::unordered_map<TreeNode*, vector<TreeNode*>> graph;
public:
	int findClosestLeaf(TreeNode* root, int k) {
		TreeNode * temp = NULL;
		std::queue<TreeNode*> pile;
		std::unordered_set<TreeNode*> leaves;
		while (!pile.empty()) {
			int sz = static_cast<int>(pile.size());
			int i = 0;
			while (i < sz) {
				TreeNode * parent = pile.front();
				pile.pop();
				if (parent->val == k) {
					temp = parent;
				}
				if (parent->left != 0) {
					graph[parent].pb(parent->left);
					graph[parent->left].pb(parent);
					pile.push(parent->left);
				}
				if (parent->right != 0) {
					graph[parent].pb(parent->right);
					graph[parent->right].pb(parent);
					pile.push(parent->right);
				}
				if (parent->left == NULL && parent->right == NULL)leaves.insert(parent);
				++i;
			}
		}
		std::unordered_set<TreeNode*> visited;
		std::queue<pair<TreeNode*, int>> pile2;
		pile2.push({ temp,0 });
		visited.insert(temp);
		while (!pile2.empty()) {
			int sz = (int)pile2.size();
			int i = 0;
			while (i < sz) {
				TreeNode * current = pile2.front().first;
				int weight = pile2.front().second;
				if (leaves.count(current) > 0)return (*current)val;
				pile2.pop();
				for (auto& x : graph[current]) {
					if (visited.count(x) == 0) {
						visited.insert(x);
						pile2.push({ x,weight + 1 });
					}
				}
				++i;
			}
		}
		return -1;
	}
};