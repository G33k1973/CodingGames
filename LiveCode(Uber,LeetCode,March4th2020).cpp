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
	TreeNode * z;
	bool isLCA(TreeNode *r, TreeNode * p, TreeNode * q, int& c) {
		if (r == 0)return false;
		if (r == p)++c;
		if (r == q)++c;
		if (c == 2)return true;
		return isLCA(r->left, p, q, c) || isLCA(r->right, p, q, c);
	}
	void preorder(TreeNode * r, TreeNode * p, TreeNode *q) {
		if (r == 0)return;
		int c = 0;
		if (isLCA(r, p, q, c))z = r;
		preorder(r->left, p, q);
		preorder(r->right, p, q);
		return;
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == 0)return NULL;
		z = 0;
		preorder(root, p, q);
		return z;
	}
};

class Solution {
public:
	int compareVersion(string version1, string version2) {
		version1 += " ";
		version2 += " ";
		int n = int(version1.size());
		int m = int(version2.size());
		vector<string> f1, f2;
		int i = 0;
		string sub = "";
		int c1 = 0, c2 = 0;
		while (i < n) {
			char x = version1[i++];
			if (x == '.') {
				++c1;
				if (sub.empty())sub = "0";
				f1.push_back(sub);
				sub.clear();
			}
			else if (x == ' ') {
				++c1;
				if (sub.empty())sub = "0";
				f1.push_back(sub);
				sub.clear();
				break;
			}
			else {
				if (!sub.empty() || x != '0')sub.push_back(x);
			}
		}
		sub.clear();
		i = 0;
		while (i < m) {
			char x = version2[i++];
			if (x == '.') {
				++c2;
				if (sub.empty())sub = "0";
				f2.push_back(sub);
				sub.clear();
			}
			else if (x == ' ') {
				++c2;
				if (sub.empty())sub = "0";
				f2.push_back(sub);
				sub.clear();
				break;
			}
			else {
				if (!sub.empty() || x != '0')sub.push_back(x);
			}
		}
		int j = 0;
		i = 0;
		while (i < c1&&j < c2) {
			//cout<<f1[i]<<" "<<f2[j]<<endl;
			int s1 = int(f1[i].size());
			int s2 = int(f2[j].size());
			if (s1 > s2)return 1;
			if (s1 < s2)return -1;
			if (s1 == s2) {
				if (f1[i] < f2[j])return -1;
				if (f1[i] > f2[j])return 1;
			}
			++i, ++j;
		}
		while (i < c1) {
			if (f1[i] != "0")return 1;
			++i;
		}
		while (j < c2) {
			if (f2[j] != "0")return -1;
			++j;
		}
		return 0;
	}
};