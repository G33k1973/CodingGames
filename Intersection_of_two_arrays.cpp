#define pb push_back
class Solution {
protected:
	vector<int> res;
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int n = int(nums1.size());
		int m = int(nums2.size());
		if (n == 0 || m == 0)return res;
		int i{ 0 }, j{ 0 };
		sort(begin(nums1), end(nums1), less<int>());
		sort(begin(nums2), end(nums2), less<int>());
		while (i < n&&j < m) {
			int x = nums1[i];
			int y = nums2[j];
			if (x == y) {
				res.pb(x);
				++i, ++j;
				continue;
			}
			else if (x < y)++i;
			else if (x > y)++j;
		}
		return res;
	}
};