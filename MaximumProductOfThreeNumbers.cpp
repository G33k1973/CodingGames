using ll = long long int;
class Solution {
protected:
	int res;
	int GetProduct(int *a, int *b, int *c) {
		return (*a)*(*b)*(*c);
	}
public:
	int maximumProduct(vector<int>& nums) {
		res = INT_MIN;
		int n = static_cast<int>(nums.size());
		if (n < 3)return 0;
		if (n == 3) {
			res = GetProduct(nums.data(), nums.data() + 1, nums.data() + 2);
			return res;
		}
		std::sort(begin(nums), end(nums), less<int>());
		if (nums.front() >= 0) {
			int *a = nums.data() + n - 1;
			int *b = nums.data() + n - 2;
			int *c = nums.data() + n - 3;
			return GetProduct(a, b, c);
		}
		if (nums.back() <= 0) {
			if (nums.back() == 0)return 0;
			int *a = nums.data() + n - 1;
			int *b = nums.data() + n - 2;
			int *c = nums.data() + n - 3;
			return GetProduct(a, b, c);
		}
		int *a = nums.data() + n - 1;
		int *b = nums.data() + n - 2;
		int *c = nums.data() + n - 3;
		int res1 = GetProduct(a, b, c);
		b = nums.data();
		c = nums.data() + 1;
		int res2 = GetProduct(a, b, c);
		res = max(res1, res2);
		return res;
	}
};