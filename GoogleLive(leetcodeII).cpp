class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n0(0), n1(0), n2(0);
		int n = int(nums.size());
		for (int& i : nums) {
			switch (i) {
			case 0:++n0;
				break;
			case 1:++n1;
				break;
			case 2:++n2;
				break;
			default:
				break;
			}
		}
		int i = 0;
		while (i < n0) {
			nums[i++] = 0;
		}
		while (i < (n0 + n1))nums[i++] = 1;
		while (i < (n0 + n1 + n2))nums[i++] = 2;
	}
};

class Solution {
public:
	string removeKdigits(string num, int k) {
		int l = static_cast<int>(num.length());
		if (k >= l)return "0";
		vector<char> st;
		for (int i = 0; i < l; ++i) {
			char x = num.at(i);
			while (!st.empty() && x < st.back() && k) {
				--k;
				st.pop_back();
			}
			if (!st.empty() || x != '0')st.push_back(x);
		}
		while (!st.empty() && k) {
			st.pop_back();
			--k;
		}
		return (st.empty()) ? ("0") : (string(begin(st), end(st)));
	}
};