#define pb push_back
class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		const int n = int(nums.size());
		if (!n)return 0;
		if (n == 1) {
			if (nums.at(0) > 0)return 1;
			return 0;
		}
		vector<int> zeros;
		vector<int> neg;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 0)zeros.pb(i);
			else if (nums[i] < 0)neg.pb(i);
		}
		int lz = int(zeros.size());
		int ln = int(neg.size());
		if (!lz && !ln)return n;
		if (!lz) {
			if (!(ln & 1))return n;
			int lb = neg.front(), ub = neg.back();
			//[0...ub-1]
			//[lb+1...n-1]
			return max(ub, n - lb - 1);
		}
		int res = 0, left, right, len, lb, ub;
		int c = 0;
		for (int i = 0; i < lz; ++i) {
			if (i == 0) {
				//[0...i-1]
				left = 0, right = zeros[i] - 1;
			}
			else {
				left = zeros[i - 1] + 1, right = zeros[i] - 1;
			}
		work:
			len = right - left;
			//cout<<len<<endl;
			if (len == 0) {
				if (i != lz - 1)continue;
				//else goto lab;
			}
			auto it = lower_bound(begin(neg), end(neg), left);
			if (it == end(neg) || *it > right) {
				res = max(res, len + 1);
			}
			else {
				auto it2 = lower_bound(begin(neg), end(neg), right);
				if (it2 == end(neg) || *it2 > right)--it2;
				lb = *it, ub = *it2;
				int num = distance(it, it2) + 1;
				if (!(num & 1)) {
					res = max(res, len + 1);
					if (i != lz - 1)continue;
				}
				//[left...ub-1]
				//[lb+1...right]
				else res = max(res, max(ub - left, right - lb));
			}
			//cout<<"here...\n";
			if (i == lz - 1) {
			lab:              if (c == 1)break;
				left = zeros[i] + 1;
				right = n - 1;
				if (left >= right)continue;
				++c;
				goto work;
			}
		}
		return res;
	}
};