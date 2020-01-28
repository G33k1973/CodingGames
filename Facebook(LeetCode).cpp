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
	void dfs(TreeNode * r) {
		if (r != NULL) {
			dfs(r->left);
			arr.push_back(r->val);
			dfs(r->right);
		}
	}
public:
	int closestValue(TreeNode* root, double target) {
		assert(root != NULL);
		dfs(root);
		int lb = static_cast<int>(std::floor(target));
		int up = static_cast<int>(std::ceil(target));
		if (lb != up) {
			auto it = std::lower_bound(begin(arr), end(arr), lb);
			if (it == end(arr))return arr.back();
			int val1 = *it;
			if (next(it, 1) == arr.end())return val1;
			++it;
			int val2 = *it;
			return ((target - val1) < (val2 - target)) ? (val1) : (val2);
		}
		auto it = std::lower_bound(begin(arr), end(arr), lb);
		if (it == end(arr))return arr.back();
		if (*it == lb)return lb;
		int x = *it;
		if (it == begin(arr))return *it;
		--it;
		return ((lb - *it) < (x - lb)) ? (*it) : (x);
	}
};

class Solution {
public:
	string simplifyPath(string path) {
		int l = int(path.length());
		if (l == 0)return "/";
		stack<string> directories;
		int i = 0;
		string sub("");
		while (i < l) {
			char x = path.at(i);
			if (x == '.'&&i < (l - 1) && path[i + 1] == '.') {
				if (!sub.empty()) {
					directories.push(sub);
					sub.clear();
				}
				if (directories.empty() == false)directories.pop();
				i += 2;
				continue;
			}
			if (isalpha(x))sub.push_back(x);
			else {
				if (!sub.empty()) {
					directories.push(sub);
					sub.clear();
				}
			}
			++i;
		}
		vector<string> arr;
		if (directories.empty())return "/";
		while (!directories.empty()) {
			arr.push_back(directories.top());
			directories.pop();
		}
		reverse(begin(arr), end(arr));
		string res = string(1, '/');
		for (auto& x : arr) {
			res += x;
			res += "/";
		}
		res.pop_back();
		return res;
	}
};

#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
ll mul(ll a, ll b) {
	ll res = 0;
	a %= M;
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a * 2) % M;
	}
	return res;
}
int Solution::solve(int A, int B) {
	if (A > B)return 0;
	ll result = 1ULL;
	while (A--) {
		result = mul(result, B);
		--B;
	}
	return int(result);
}
