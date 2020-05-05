class Solution {
protected:
	static bool IsSmaller(const vector<int>& a, const vector<int>& b) {
		int wa = a[0], ha = a[1];
		int wb = b[0], hb = b[1];
		return (wa < wb&&ha < hb);
	}
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		int n = static_cast<int>(envelopes.size());
		if (n == 0)return 0;
		if (n == 1)return 1;
		sort(begin(envelopes), end(envelopes), [&](const vector<int>& a, const vector<int>& b) {
			int wa = a[0], ha = a[1];
			int wb = b[0], hb = b[1];
			if (wa < wb&&ha < hb)return 1;
			if (max(wa, ha) < max(wb, hb))return 1;
			return 0;
		});
		vector<int> dp(n, 1);
		int i, j;
		for (i = 1; i < n; ++i) {
			for (j = 0; j < i; ++j) {
				if (Solution::IsSmaller(envelopes[j], envelopes[i]) && dp[i] < 1 + dp[j])
					dp[i] = 1 + dp[j];
			}
		}
		return *max_element(begin(dp), end(dp));
	}
};