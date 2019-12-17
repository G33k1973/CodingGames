#define pb push_back
class Solution {
protected:
	vector<vector<int>> res;
	map<vector<int>, int> seen;
	int n;
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		this->n = int(nums.size());
		if (n < 3)return res;
		sort(begin(nums), end(nums), less<int>());
		int i, j;
		for (i = 0; i < n - 2; ++i) {
			if (nums[i] > 0)break;
			int x = nums[i];
			if (i > 0 && x == nums[i - 1])continue;
			for (j = i + 1; j < n - 1; ++j) {
				int y = nums[j];
				int z = x + y;
				if (z > 0 && y >= 0)break;
				int target = -z;
				if (binary_search(begin(nums) + j + 1, end(nums), target)) {
					vector<int> temp{ x,y,target };
					if (seen.find(temp) == end(seen)) {
						seen.insert(make_pair(temp, 1));
						res.pb(temp);
					}
				}
			}
		}
		return res;
	}
};