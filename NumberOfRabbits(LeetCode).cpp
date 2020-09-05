class Solution {
public:
	int numRabbits(vector<int>& answers) {
		const int n = int(answers.size());
		unordered_map<int, int> h;
		int res = 0;
		for (auto& x : answers) {
			if (!x)++res;
			else
				++h[x];
		}
		for (auto& x : h) {
			int freq = x.second;
			int num = freq / (x.first + 1);
			if (!num)res += (x.first + 1);
			else {
				int rem = freq % (x.first + 1);
				res += (rem > 0) ? ((num + 1)*(x.first + 1)) : (num*(x.first + 1));
			}
		}
		return res;
	}
};