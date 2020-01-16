#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
class Solution {
protected:
	std::function<ll(ll)> myfun = [](ll x) {return (x > 0) ? (x) : (-x); };
public:
	int divide(int dividend, int divisor) {
		ll d1 = static_cast<ll>(dividend);
		ll d2 = static_cast<ll>(divisor);
		bool sign = ((d1*d2) > 0);
		d1 = myfun(d1);
		d2 = myfun(d2);
		ll result = 0;
		ll cum = 0;
		while (1) {
			cum += d2;
			if (cum > d1)break;
			++result;
		}
		if (sign == false)result = -result;
		if (result<static_cast<ll>(INT_MIN) || result>static_cast<ll>(INT_MAX))return INT_MAX;
		return int(result);
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
#define pb push_back
class BSTIterator {
protected:
	int i, n;
	vector<int> arr;
private:
	void dfs(TreeNode * r) {
		if (r != 0) {
			dfs(r->left);
			arr.pb(r->val);
			++n;
			dfs(r->right);
		}
	}
public:
	BSTIterator(TreeNode* root) {
		i = 0, n = 0;
		if (root != 0) {
			i = 0;
			dfs(root);
		}
	}

	/** @return the next smallest number */
	int next() {
		return arr[i++];
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return i < n;
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

class Solution {
private:
	enum color { NONE, BLACK, WHITE };
	vector<color> col;
	bool bfs(vector<bool>& visited, vector<vector<int>>& graph, int src) {
		visited.at(src) = true;
		col[src] = WHITE;
		queue<int> pile;
		pile.push(src);
		while (!pile.empty()) {
			int sz = int(pile.size());
			int i = 0;
			while (i < sz) {
				int node = pile.front();
				int kindcolor = col.at(node);
				pile.pop();
				for (auto& y : graph[node]) {
					if (visited[y]) {
						if (col[y] == kindcolor)return false;
					}
					else if (!visited[y]) {
						visited[y] = true;
						col[y] = (kindcolor == BLACK) ? (WHITE) : (BLACK);
						pile.push(y);
					}
				}
				++i;
			}
		}
		return true;
	}
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = int(graph.size());
		if (n < 2)return true;
		vector<bool> visited(n, false);
		col.assign(n, NONE);
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				if (!bfs(visited, graph, i))return false;
			}
		}
		return true;
	}
};

