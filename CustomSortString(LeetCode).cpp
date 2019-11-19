#define pb push_back
class Solution {
protected:
	vector<char> pile;
	int h[26];
public:
	string customSortString(string S, string T) {
		int l = int(S.size());
		if (l == 0)return T;
		int n = int(T.size());
		if (n == 0)return T;
		memset(h, 0, sizeof(int) * 26);
		for (auto& x : S) {
			pile.pb(x);
			h[x - 'a'] = 1;
		}
		int h2[26] = { 0 };
		string nogood(""), good("");
		for (auto& y : T) {
			if (h[y - 'a'] == 0) {
				nogood.pb(y);
			}
			else {
				++h2[y - 'a'];
			}
		}
		for (auto& x : pile) {
			if (h2[x - 'a'] == 0)continue;
			good += string(h2[x - 'a'], x);
		}
		good += nogood;
		return good;
	}
};