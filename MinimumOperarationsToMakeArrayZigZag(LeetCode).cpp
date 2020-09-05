class Solution {
protected:
public:
	int movesToMakeZigzag(vector<int>& nums) {
		const int n = int(nums.size());
		if (n < 2)return 0;
		int i = 1;
		int left = nums[0];
		int res = 0;
		while (i < n) {
			int right = (i + 1 >= n) ? (INT_MAX) : (nums[i + 1]);
			int x = nums[i];
			if (x >= left) {
				int diff = x - left + 1;
				x -= diff;
				res += diff;
			}
			if (x >= right) {
				int diff = x - right + 1;
				x -= diff;
				res += diff;
			}
			left = right;
			i += 2;
		}
		int res2 = 0;
		left = nums[0];
		i = 1;
		while (i < n) {
			int right = (i + 1 >= n) ? (INT_MIN) : (nums[i + 1]);
			int x = nums[i];
			if (x <= left) {
				int diff = left - x + 1;
				left -= diff;
				res2 += diff;
			}
			if (x <= right) {
				int diff = right - x + 1;
				right -= diff;
				res2 += diff;
			}
			left = right;
			i += 2;
		}
		return min(res, res2);
	}
};