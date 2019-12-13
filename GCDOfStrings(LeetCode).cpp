#define pb push_back
class Solution {
protected:
	int mygcd(int a, int b) {
		if (a == 0)
			return b;
		return mygcd(b%a, a);
	}
	bool dfs(const std::string& s, int l, int i, const std::string& t, int m) {
		if (i == l)return true;
		std::string::size_type pos = s.find(t, i);
		if (pos != i)return false;
		return dfs(s, l, i + m, t, m);
	}
public:
	string gcdOfStrings(string str1, string str2) {
		int n = static_cast<int>(str1.length());
		int m = static_cast<int>(str2.length());
		if (n == 0 || m == 0)return "";
		int h1[26] = { 0 }, h2[26] = { 0 };
		for (auto& x : str1) {
			if (h1[x - 'A'] == 0)h1[x - 'A'] = 1;
		}
		for (auto& x : str2) {
			if (h2[x - 'A'] == 0)h2[x - 'A'] = 1;
		}
		for (int i = 0; i < 26; ++i) {
			if (h1[i] != h2[i])return "";
		}
		int GCD{ this->mygcd(n,m) };
		vector<int> a;
		for (int i = 1; i*i <= GCD; ++i) {
			if (GCD%i == 0) {
				int d1 = i, d2 = GCD / i;
				if (d1 == d2)a.pb(d1);
				else {
					a.pb(d1);
					a.pb(d2);
				}
			}
		}
		sort(begin(a), end(a), greater<int>());
		for (const auto& x : a) {
			string sub = str1.substr(0, x);
			if (dfs(str1, n, 0, sub, x) && dfs(str2, m, 0, sub, x))return sub;
		}
		return string("");
	}
};