#define pb push_back
class Solution {
public:
	vector<int> partitionLabels(string S) {
		int h[26];
		memset(h, -1, sizeof(h));
		int l = int(S.size());
		if (l == 0)return vector<int>{0};
		if (l == 1)return vector<int>{1};
		int i = 0;
		while (i < l) {
			h[S[i] - 'a'] = i;
			++i;
		}
		i = 0;
		int jlim = -1;
		int start = 0;
		vector<int> res;
		while (i < l) {
			int k = h[S[i] - 'a'];
			if (jlim == -1) {
				jlim = k;
			}
			if (k > jlim)jlim = k;
			else if (i == jlim) {
				int distance = jlim - start + 1;
				jlim = -1;
				start = i + 1;
				res.pb(distance);
			}
			++i;
		}
		return res;
	}
};