class Solution {
public:
	string removeKdigits(string num, int k) {
		vector<char> s;
		int count = 0;
		for (char const& c : num) {
			while (!s.empty() && c < s.back() && count++ < k) s.pop_back();
			if (!s.empty() || c != '0') s.push_back(c);
		}
		while (!s.empty() && count++ < k) s.pop_back();
		return s.size() > 0 ? string(s.begin(), s.end()) : "0";
	}
};