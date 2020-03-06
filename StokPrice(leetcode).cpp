class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = int(prices.size());
		if (n < 2)return 0;
		vector<int> greater(n, -1);
		greater[n - 1] = prices.back();
		for (int i = n - 2; i >= 0; --i) {
			greater[i] = max(greater[i + 1], prices[i]);
		}
		int buy = prices.at(0);
		int res = 0;
		for (int i = 1; i < n; ++i) {
			int x = prices[i];
			if (x <= buy)
				buy = x;
			else {
				res = max(res, greater[i] - buy);
			}
		}
		return res;
	}
};