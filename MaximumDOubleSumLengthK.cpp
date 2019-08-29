class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int n = static_cast<int>(nums.size());
		if (n < k)return 0.0;
		int i, j;
		double res = -std::numeric_limits<double>::max();
		for (i = 0; i < n; ++i) {
			if ((n - i) < k)break;
			int l = 0;
			double sum = 0.0;
			for (j = i; j < n; ++j) {
				++l;
				sum += nums[j];
				if (l >= k) {
					res = max(res, sum / (1.*l));
				}
			}
		}
		return res;
	}
};