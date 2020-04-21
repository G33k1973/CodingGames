class Solution {
private:
	vector<int> sx;
	bool ispossible(vector<int>& a, int n, int m, int cum, int& best) {
		int i = 0;
		int curmax = 0;
		int sub = 0;
		while (i < n) {
			int left = n - i;
			if (m == 1) {
				sub += sx[i];
				curmax = max(sub, curmax);
				break;
			}
			if (sub + a[i] <= cum) {
				sub += a[i];
			}
			else {
				curmax = max(sub, curmax);
				--m;
				sub = a[i];
			}
			++i;
		}
		if (curmax > cum)return false;
		best = min(best, curmax);
		return true;
	}
public:
	int splitArray(vector<int>& nums, int m) {
		int n = int(nums.size());
		assert(m <= n);
		if (n == 0)return 0;
		if (n == m)return *max_element(begin(nums), end(nums));
		int sum = accumulate(begin(nums), end(nums), 0);
		int low = 0, high = sum;
		sx.assign(n + 1, 0);
		int i = n - 1;
		while (i >= 0) {
			sx[i] = nums[i] + sx[i + 1];
			--i;
		}
		int res = sum;
		while (low <= high) {
			int middle = low + (high - low) / 2;
			if (ispossible(nums, n, m, middle, res)) {
				high = middle - 1;
			}
			else {
				low = middle + 1;
			}
		}
		return res;
	}
};