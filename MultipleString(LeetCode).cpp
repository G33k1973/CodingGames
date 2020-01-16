class Solution {
private:
	bool IsGood(string& s, int l, int i, int n, string& t) {
		if (i == l)return true;
		std::string::size_type pos = s.find(t, i);
		if (pos != i)return false;
		return IsGood(s, l, i + n, n, t);
	}
public:
	bool repeatedSubstringPattern(string s) {
		int l = int(s.size());
		if (l < 2)return false;
		vector<int> factors{ 1 };
		for (int i = 2; i*i <= l; ++i) {
			if (l%i == 0) {
				int d1 = i, d2 = l / i;
				if (d1 == d2)factors.push_back(d1);
				else {
					vector<int> temp{ d1,d2 };
					factors.insert(factors.end(), temp.begin(), temp.end());
				}
			}
		}
		if (factors.size() == 0)return false;
		sort(begin(factors), end(factors));
		for (auto& x : factors) {
			string t = s.substr(0, x);
			if (IsGood(s, l, 0, x, t))return true;
		}
		return false;
	}
};