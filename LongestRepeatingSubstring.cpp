class Solution {
public:
	string longestDupSubstring(string S) {
		s = move(S);
		createPowr();
		int l = 1, r = s.size(), maxLen = 0, pos = 0;
		while (l < r) {
			int len = (l + r) / 2;
			if (auto[hasDup, i] = isDupExist(len); hasDup) {
				maxLen = len;
				pos = i;
				l = len + 1;
			}
			else r = len;
		}
		return s.substr(pos - maxLen + 1, maxLen);
	}

	pair<bool, int> isDupExist(int len) {
		unordered_map<long long, int> m;  //hash, index
		long long hash = 0;
		int i = 0;
		for (; i < len; i++) hash = rollhash(i, len, hash);
		m[hash] = i - 1;
		for (; i < s.size(); i++) {
			hash = rollhash(i, len, hash);
			if (m.count(hash)) {
				int j = m[hash];
				if (s.substr(j - len + 1, len) == s.substr(i - len + 1, len)) return { true, i };
			}
			m[hash] = i;
		}
		return { false, -1 };
	}

	long long rollhash(int i, int len, long long preHash) {
		auto res = preHash;
		if (i - len >= 0)
			res -= powr[len - 1] * (s[i - len] - 'a');
		res = res % mod + mod;
		res *= r;
		res += (s[i] - 'a');
		return (res + mod) % mod;
	}

	void createPowr() {
		powr.reserve(s.size());
		long long pow = 1;
		for (int i = 0; i < s.size(); i++) {
			powr.push_back(pow);
			pow *= r;
			pow %= mod;
		}
	}

	const long long mod = 1e9 + 7;
	const long long r = 10007;
	vector<long long> powr;
	string s;
};