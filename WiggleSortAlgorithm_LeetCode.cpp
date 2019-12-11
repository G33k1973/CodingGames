class Solution {
protected:
	void MySwap(int *x, int *y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
		return;
	}
public:
	void wiggleSort(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		int p = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (p == 0) {
				if (nums[i] > nums[i + 1]) {
					MySwap(&nums[i], &nums[i + 1]);
				}
			}
			else if (p == 1) {
				if (nums[i] < nums[i + 1]) {
					MySwap(&nums[i], &nums[i + 1]);
				}
			}
			p = !p;
		}
	}
};