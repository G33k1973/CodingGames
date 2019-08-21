class Solution {
public:
	int maxSubArrayLen(vector<int>& nums, int k) {
		int n = (int)nums.size();
		if (n == 0) {
			return 0;
		}
		unordered_map<int, int> h;
		int sum = 0;
		int i;
		int res = 0;
		for (i = 0; i < n; ++i) {
			sum += nums[i];
			if (sum == k)res = max(res, i + 1);
			auto it = h.find(sum - k);
			if (it != end(h)) {
				res = max(res, i - it->second);
			}
			it = h.find(sum);
			if (it == end(h))h[sum] = i;
		}
		return res;
	}
};