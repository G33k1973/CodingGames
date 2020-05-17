class Solution {
protected:
	vector<int> bs(vector<int>& a, int l, int h, int x) {
		vector<int> r{ -1,-1 };
		if (l > h)return r;
		int m;
		int L(l), H(h);
		int j = -1;
		while (l <= h) {
			m = l + (h - l) / 2;
			if (a[m] == x) {
				j = m;
				break;
			}
			if (a[m] > x) {
				h = m - 1;
			}
			else if (a[m] < x) {
				l = m + 1;
			}
		}
		if (j == -1)return r;
		int i = j;
		while (i >= L && a[i] == x)--i;
		++i;
		r.front() = i;
		i = j;
		while (i <= H && a[i] == x)++i;
		--i;
		r.back() = i;
		return r;
	}
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		const int n = int(nums.size());
		return bs(nums, 0, n - 1, target);
	}
};