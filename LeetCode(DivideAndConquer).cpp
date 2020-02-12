//Divide and Conquer for finding peak element index
class Solution {
private:
	int dc(vector<int>& nums, int l, int h, int n) {
		if (l > h)return -1;
		int m = l + (h - l) / 2;
		if ((m == 0 || (m > 0 && nums[m - 1] < nums[m])) &&
			(m == (n - 1) || (m < (n - 1) && nums[m + 1] < nums[m])))return m;
		if (m&&nums[m - 1] >= nums[m])return dc(nums, l, m - 1, n);
		return dc(nums, m + 1, h, n);
	}
public:
	int findPeakElement(vector<int>& nums) {
		int n = int(nums.size());
		if (n == 0)return -1;
		if (n == 1)return 0;
		return dc(nums, 0, n - 1, n);
	}
};

#define pb push_back
class Solution {
private:
	bool ispossible(const std::string& s, int l, int i, string& t, int m) {
		if (i == l)return true;
		std::string::size_type pos = s.find(t, i);
		if (pos != i)return 0;
		return ispossible(s, l, i + m, t, m);
	}
public:
	bool repeatedSubstringPattern(string s) {
		int l = int(s.length());
		if (l < 2)return false;
		vector<int> factors{ 1 };
		for (int i = 2; i*i <= l; ++i) {
			if (l%i == 0) {
				int d1 = i, d2 = l / i;
				if (d1 == d2)factors.pb(d1);
				else {
					factors.pb(d1);
					factors.pb(d2);
				}
			}
		}
		sort(begin(factors), end(factors));
		for (int & i : factors) {
			string t = "";
			int j{ 0 };
			while (j < i) {
				t += string(1, s[j++]);
			}
			if (ispossible(s, l, 0, t, i))return true;
		}
		return false;
	}
};