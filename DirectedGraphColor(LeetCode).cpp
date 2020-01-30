#define pb push_back
#define mp make_pair
using ip = pair<int, int>;
using iip = pair<ip, int>;
class Solution {
private:
	enum col { RED = 0, BLUE };
	vector<int> result;
	unordered_map<int, unordered_map<int, vector<int>>> graph;
	vector<vector<bool>> visited;
	int bfs(int src, int dst, int color, int n) {
		visited.assign(n, vector<bool>(2, false));
		std::queue<iip> pile;
		pile.push(mp(mp(src, color), 0));
		visited[src][color] = true;
		while (!pile.empty()) {
			int sz = int(pile.size());
			int i = 0;
			while (i < sz) {
				iip current = pile.front();
				pile.pop();
				int oldsrc = current.first.first;
				int oldcol = current.first.second;
				int weight = current.second;
				if (oldsrc == dst)return weight;
				for (auto& x : graph[oldsrc][!oldcol]) {
					if (!visited[x][!oldcol]) {
						visited[x][!oldcol] = true;
						pile.push(mp(mp(x, !oldcol), weight + 1));
					}
				}
				++i;
			}
		}
		return -1;
	}
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		if (n == 0)return vector<int>{};
		if (n == 1) {
			return vector<int>{0};
		}
		for (auto& x : red_edges) {
			int u = x.front(), v = x.back();
			graph[u][RED].push_back(v);
		}
		for (auto& x : blue_edges) {
			int u = x.front(), v = x.back();
			graph[u][BLUE].push_back(v);
		}
		result.assign(n, 0);
		for (int i = 1; i < n; ++i) {
			int res0 = bfs(0, i, 0, n);
			int res1 = bfs(0, i, 1, n);
			if (res0 == -1)result[i] = res1;
			else if (res1 == -1)result[i] = res0;
			else if (res0 == -1 && res1 == -1)result[i] = -1;
			else result[i] = min(res0, res1);
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
	int search(vector<int>& inorder, int n, int val) {
		int i;
		for (i = 0; i < n; ++i) {
			if (inorder[i] == val) {
				break;
			}
		}
		return i;
	}
	TreeNode * build(vector<int>& inorder, vector<int>& postorder, int n, int l, int h, int& porindex) {
		if (l > h)return NULL;
		TreeNode * root = new TreeNode(postorder[porindex]);
		--porindex;
		if (l == h)return root;
		int index = search(inorder, n, root->val);
		root->right = build(inorder, postorder, n, index + 1, h, porindex);
		root->left = build(inorder, postorder, n, l, index - 1, porindex);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = int(inorder.size());
		if (n == 0)return NULL;
		if (n == 1) {
			return new TreeNode(inorder[0]);
		}
		int i = n - 1;
		return build(inorder, postorder, n, 0, n - 1, i);
	}
};

class Solution {
private:
	bool IsPossible(int * a, int * b, int n) {
		for (int i = 0; i < n; ++i) {
			if (b[i] == 0)continue;
			if (a[i] < b[i])return false;
		}
		return true;
	}
public:
	string minWindow(string S, string T) {
		int n = int(S.length());
		int m = int(T.length());
		if (m > n)return "";
		if (m == 0)return "";
		if (n == 0)return "";
		int i = 0, j = 0;
		int ht[26] = { 0 };
		int hs[26] = { 0 };
		for (auto& x : T) {
			int j = x - 'a';
			++ht[j];
		}
		for (auto& y : S) {
			int j = y - 'a';
			++hs[j];
		}
		if (!IsPossible(hs, ht, 26))return "";
		pair<int, int> ix(INT_MAX, INT_MAX);
		while (i < n) {
			if (!IsPossible(hs, ht, 26))break;
			if (S[i] == T[j]) {
				int k = i + 1;
				++j;
				while (j < m && k < n) {
					if (S[k] == T[j]) {
						++j;
					}
					++k;
				}
				//cout<<i<<" "<<k<<endl;
				if (j == m) {
					if (ix.first == INT_MAX) {
						ix = make_pair(i, k);
					}
					else {
						int olddistance = ix.second - ix.first;
						int nudistance = k - i;
						if (nudistance < olddistance)ix = make_pair(i, k);
					}
				}
				j = 0;
			}
			--hs[S[i] - 'a'];
			++i;
		}
		return (ix.first == INT_MAX) ? ("") : (S.substr(ix.first, ix.second - ix.first));
	}
};