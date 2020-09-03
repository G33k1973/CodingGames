class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		const int n = static_cast<int>(nums.size());
		if (n == 0)return 0;
		//positions of zeros and neg
		set<int> hzero, hneg;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 0) {
				if (!i)hzero.insert(i);
				else if (nums[i - 1] != 0)hzero.insert(i);
				else if (i != n - 1 && nums[i - 1] == 0 && nums[i + 1] != 0)hzero.insert(i);
			}
			else if (nums[i] < 0)hneg.insert(i);
		}
		if (hzero.empty() && hneg.empty())return n;
		if (hzero.size() == nums.size())return 0;
		if (hzero.empty()) {
			int m = int(hneg.size());
			if (!(m & 1))return n;
			//odd number of neg numbers
			int lb = *begin(hneg);
			int ub = *prev(end(hneg), 1);
			if (lb == ub) {
				return max(lb + 1, n - ub - 1);
			}
			//i j k - until [low,k-1],[i+1,high]
			return max(lb + 1, n - lb - 1);
		}
		auto ptr = begin(hzero);
		auto prev{ ptr };
		int low = 0, high = 0;
		int res = 0;
		while (ptr != end(hzero)) {
			//find low
			if (ptr == begin(hzero)) {
				low = 0;
			}
			else {
				low = *prev + 1;
			}
			//find high
			auto ptr3 = next(ptr);
			if (ptr3 == end(hzero)) {
				high = n - 1;
			}
			else {
				high = *ptr3 - 1;
			}
			//[low,high] interval : seek number of neg numbers
			if (hneg.empty()) {
				res = max(res, high - low + 1);
			}
			else {
				auto it = hneg.lower_bound(low);
				if (it == end(hneg) || *it > high) {
					res = max(res, high - low + 1);
				}
				else {
					int lb = *it;
					int ub = lb;
					it = hneg.lower_bound(high);
					if (it != end(hneg) && *it < high)ub = *it;
					res = max(res, max(high - lb, ub - low));
				}
			}
			prev = ptr;
			++ptr;
		}
		return res;
	}
};