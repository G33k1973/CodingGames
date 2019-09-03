class Solution {
public:
	string minWindow(string S, string T) {
		int n = int(S.size());
		int m = (int)T.size();
		if (n == 0 || m == 0)return "";
		if (m > n)return "";
		if (m == n) {
			if (S == T)return S;
			return "";
		}
		int hS[26] = { 0 };
		int hT[26] = { 0 };
		for (auto& x : S)++hS[x - 'a'];
		for (auto& y : T)++hT[y - 'a'];
		for (int i = 0; i < 26; ++i) {
			if (hT[i] > hS[i])return "";
		}
		std::pair<int, int> res{ -1,INT_MAX };
		int i, j;
		for (i = 0; i < n; ++i) {
			j = 0;
			if (n - i < m)break;
			if (S[i] == T[j]) {
				int k = i;
				while (k < n&&j < m) {
					if (S[k] == T[j]) {
						++k, ++j;
					}
					else ++k;
				}
				if (j == m) {
					int d = k - i;
					if (d < res.second)res = make_pair(i, d);
				}
			}
		}
		if (res.second == INT_MAX)return "";
		return S.substr(res.first, res.second);
	}
};