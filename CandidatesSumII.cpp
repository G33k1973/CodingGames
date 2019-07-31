#define pb push_back
class Solution {
protected:
	std::map<vector<int>, int> mp;
	std::vector < vector<int>> res;
	void dfs(const std::vector<int>& a, int n, int i, const int& target, int subtotal, vector<int>& cur) {
		if (subtotal == target) {
			auto it = mp.find(cur);
			if (it == end(mp)) {
				++mp[cur];
				res.pb(cur);
			}
			return;
		}
		if (i == n)return;
		int x = a[i];
		if (subtotal + x <= target) {
			cur.pb(x);
			dfs(a, n, i + 1, target, subtotal + x, cur);
			cur.pop_back();
		}
		else if (subtotal + x > target)return;
		dfs(a, n, i + 1, target, subtotal, cur);
		return;
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		int n = (int)candidates.size();
		if (!res.empty())res.clear();
		if (n == 0)return res;
		sort(begin(candidates), end(candidates), less<int>());
		auto it = std::upper_bound(begin(candidates), end(candidates), target);
		if (it != end(candidates)) {
			candidates.resize(static_cast<int>(it - begin(candidates)));
			n = (int)candidates.size();
		}
		if (mp.size())mp.clear();
		vector<int> cur;
		dfs(candidates, n, 0, target, 0, cur);
		return res;
	}
};