/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
int Solution::solve(TreeNode* A) {
	if (A == 0)return 0;
	unordered_map<TreeNode*, unordered_set<TreeNode*>> graph;
	unordered_set<TreeNode*> leaves;
	queue<TreeNode*> pile;
	pile.push(A);
	int n = 0;
	while (!pile.empty()) {
		int sz = int(pile.size());
		n += sz;
		int i = 0;
		while (i < sz) {
			TreeNode * current = pile.front();
			pile.pop();
			if (current->left != 0) {
				graph[current->left].insert(current);
				graph[current].insert(current->left);
				pile.push(current->left);
			}
			if (current->right != 0) {
				graph[current->right].insert(current);
				graph[current].insert(current->right);
				pile.push(current->right);
			}
			if (current->left == 0 && current->right == 0)leaves.insert(current);
			++i;
		}
	}
	if (n == 1)return 0;
	int res = 0;
	unordered_set<TreeNode*> visited;
	for (TreeNode* i : leaves) {
		pile.push(i);
		visited.insert(i);
	}
	int level = 0;
	while (!pile.empty()) {
		int sz = int(pile.size());
		if (level & 1)res += sz;
		int i = 0;
		while (i < sz) {
			TreeNode * current = pile.front();
			pile.pop();
			for (auto& y : graph[current]) {
				if (visited.count(y) == 0) {
					visited.insert(y);
					pile.push(y);
				}
			}
			++i;
		}
		level = !level;
	}
	return res;
}
