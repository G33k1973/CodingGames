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
	vector<int> arr;
	int n;
	void dfs(TreeNode * r)
	{
		if (r == 0)return;
		dfs(r->left);
		arr.push_back(r->val);
		++n;
		dfs(r->right);
	}
	bool bs(int * arr, int low, int high, int x) {
		if (low > high)return false;
		int middle = low + (high - low) / 2;
		if (arr[middle] == x)return true;
		if (arr[middle] > x)return bs(arr, low, middle - 1, x);
		return bs(arr, middle + 1, high, x);
	}
public:
	bool findTarget(TreeNode* root, int k) {
		n = 0;
		dfs(root);
		if (n < 2)return false;
		for (int i = 0; i < n - 1; ++i) {
			int target = k - arr[i];
			if (bs(arr.data(), i + 1, n - 1, target))return true;
		}
		return false;
	}
};

class Solution {
private:
	int GCD(int a, int b) {
		if (a == 0)return b;
		return GCD(b%a, a);
	}
	bool ispossible(string& s, int n, int i, string& t, int m) {
		if (i == n)return true;
		std::string::size_type pos = s.find(t, i);
		if (pos != i)return 0;
		return ispossible(s, n, i + m, t, m);
	}
public:
	string gcdOfStrings(string str1, string str2) {
		int n = int(str1.length());
		int m = int(str2.length());
		if (n == 0 || m == 0)return "";
		int l = GCD(n, m);
		vector<int> f{ 1,l };
		for (int i = 2; i*i <= l; ++i) {
			if (l%i == 0) {
				int d1 = i, d2 = l / i;
				if (d1 == d2)f.push_back(d1);
				else {
					f.push_back(d1);
					f.push_back(d2);
				}
			}
		}
		sort(begin(f), end(f), greater<int>());
		for (int& i : f) {
			string sub = str1.substr(0, i);
			string sub2 = str2.substr(0, i);
			if (sub.compare(sub2) == 0 && ispossible(str1, n, 0, sub, i) && ispossible(str2, m, 0, sub2, i))return sub;
		}
		return "";
	}
};