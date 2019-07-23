class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		for (auto& x : nums) {
			if (x == 0)x = -1;
		}
		std::unordered_map<int, int> memo;
		int i = 0;
		int res = 0;
		int sum = 0;
		int n = (int)nums.size();
		while (i < n) {
			int x = nums[i];
			sum += x;
			if (sum == 0)res = max(res, i + 1);
			auto it = memo.find(sum);
			if (it == end(memo)) {
				memo[sum] = i;
			}
			else {
				res = max(res, i - it->second);
			}
			++i;
		}
		return res;
	}
};