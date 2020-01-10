class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int n = int(candies.size());
		if (n == 0)return 0;
		unordered_set<int> h;
		for (auto& x : candies)h.insert(x);
		return min(h.size(), N / 2);
	}
};