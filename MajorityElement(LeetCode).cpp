#define pb push_back
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		if (n == 0)return vector<int>{};
		int freq = n / 3;
		unordered_set<int> seen;
		vector<int> pile;
		unordered_map<int, int> h;
		for (auto& x : nums) {
			if (seen.count(x) == 0) {
				seen.insert(x);
				pile.pb(x);
			}
			++h[x];
		}
		vector<int> result;
		for (const int& i : pile) {
			if (h[i] > freq)result.pb(i);
		}
		return result;
	}
};