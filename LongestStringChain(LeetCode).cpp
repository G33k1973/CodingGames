#define pb push_back
class Solution {
protected:
	map<int, vector<string>> h;
	unordered_map<string, int> dp;
	bool ismatch(string& a, string& b, int l) {
		//b is longer by one character
		int diff = 0, i = 0, j = 0;
		while (i < l + 1 && j < l) {
			if (b[i] != a[j]) {
				if (diff == 1)return false;
				++i;
				++diff;
				continue;
			}
			++i, ++j;
		}
		bool ans = ((diff == 1 && (i == l + 1 && j == l)) || (diff == 0 && j == l));
		//cout<<std::boolalpha;
		//cout<<a<<" "<<b<<" "<<ans<<"\n";
		return ans;
	}
	int res{ 1 };
	int dfs(string& s, int l) {
		auto it = dp.find(s);
		if (it != end(dp))return it->second;
		//seek string of length l+1
		auto it2 = h.find(l + 1);
		if (it2 == end(h)) {
			return 0;
		}
		int ans = 0;
		for (auto& x : it2->second) {
			if (ismatch(s, x, l))ans = max(ans, 1 + dfs(x, l + 1));
		}
		return dp[s] = ans;
	}
public:
	int longestStrChain(vector<string>& words) {
		const int l = int(words.size());
		if (l == 0)return 0;
		if (l == 1)return 1;
		for (auto& x : words)h[int(x.length())].pb(x);
		auto ptr = begin(h);
		int m = int(h.size());
		while (ptr != prev(end(h), 1)) {
			int maxgain = m;
			if (m <= res)break;
			for (auto& x : ptr->second) {
				res = max(res, 1 + dfs(x, int(x.size())));
			}
			--m, ++ptr;
		}
		return res;
	}
};