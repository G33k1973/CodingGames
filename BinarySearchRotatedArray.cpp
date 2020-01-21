class Solution {
protected:
	int search(vector<int>& a, int low, int high, int target) {
		if (low > high)return -1;
		int middle = low + (high - low) >> 1;
		if (a[middle] == target)return middle;
		if (a[low] <= a[middle]) {
			if (target >= a[low] && target <= a[middle])return search(a, low, middle - 1, target);
			return search(a, middle + 1, high, target);
		}
		if (a[middle] <= a[high]) {
			if (target >= a[middle] && target <= a[high])return search(a, middle + 1, high);
		}
		return search(a, low, middle - 1, target);
	}
public:
	int search(vector<int>& nums, int target) {
		int n = int(nums.size());
		if (n == 0)return -1;
		if (n == 1) {
			return (target == nums.front()) ? (0) : (-1);
		}
		for (int i = 0; i < n; ++i)if (nums[i] == target)return i;
		return -1;
	}
};