class Solution {
public:
	bool splitArray(vector<int>& nums) {
		int n = (int)nums.size();
		int i, j, k;
		int sum1, sum2, sum3, sum4;
		int sum = 0;
		vector<int> px(n, 0), sx(n, 0);
		for (i = 0; i < n; ++i) {
			px[i] = sum;
			sum += nums[i];
		}
		i = n - 2;
		while (i >= 0) {
			sx[i] = sx[i + 1] + nums[i + 1];
			--i;
		}
		for (i = 1; i < n; ++i) {
			sum1 = sum - sx[i - 1];
			for (j = i + 2; j < n - 1; ++j) {
				sum2 = sum - px[i + 1] - sx[j - 1];
				for (k = j + 2; k < n - 1; ++k) {
					sum3 = sum - px[j + 1] - sx[k - 1];
					sum4 = sum - px[k + 1];
					if (sum1 == sum2 && sum1 == sum3 && sum1 == sum4)return 1;
				}
			}
		}
		return 0;
	}
};