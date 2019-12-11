#define pb push_back
class Solution {
protected:
	std::map<int, int, greater<int>> mp;
	int n;
	vector<int> res;
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		this->n = static_cast<int>(nums.size());
		if (n == 0)return res;
		assert(k <= n);
		int i;
		for (i = 0; i < k; ++i) {
			++mp[nums[i]];
		}
		res.pb(begin(mp)->first);
		for (i = k; i < n; ++i) {
			int x = nums[i - k];
			auto it = mp.find(x);
			--it->second;
			if (it->second == 0)mp.erase(it);
			++mp[nums[i]];
			res.pb(begin(mp)->first);
		}
		return res;
	}
};