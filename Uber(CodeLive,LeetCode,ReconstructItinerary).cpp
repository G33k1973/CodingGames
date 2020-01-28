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
private:
	int res;
	void dfs(TreeNode *r, int& res, int& k) {
		if (r == 0)return;
		dfs(r->left, res, k);
		--k;
		if (k == 0) {
			res = r->val;
			return;
		}
		dfs(r->right, res, k);
		if (res != INT_MIN)return;
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		if (root == nullptr)return -1;
		res = INT_MIN;
		dfs(root, res, k);
		return res;
	}
};

#define pb push_back
class Solution {
private:
	vector<string> res;
	bool isdone;
	unordered_map<string, vector<string>> graph;
	void dfs(string src, int edges, int n, vector<string>& a) {
		//cout<<src<<endl;
		a.pb(src);
		if (n == edges) {
			isdone = !isdone;
			res = a;
			return;
		}
		std::unordered_map<string, vector<string>>::iterator it = graph.find(src);
		if (it == end(graph)) {
			a.pop_back();
			return;
		}
		for (string& i : it->second) {
			if (i == "")continue;
			string olddest = i;
			i = "";
			dfs(olddest, edges + 1, n, a);
			if (isdone)return;
			i = olddest;
		}
		a.pop_back();
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		int n = int(tickets.size());
		if (n == 0)return res;
		if (n == 1) {
			res.pb(tickets.front().front());
			res.pb(tickets.front().back());
			return res;
		}
		for (vector<string>& i : tickets) {
			graph[i.front()].pb(i.back());
		}
		for (std::pair<const string, vector<string>>& i : graph) {
			sort(i.second.begin(), i.second.end());
		}
		string source("JFK");
		this->isdone = false;
		vector<string> a;
		dfs(source, 0, n, a);
		return res;
	}
};