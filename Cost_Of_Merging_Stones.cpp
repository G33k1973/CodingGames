#define INF 999999
using ll = long long int;
#define pb push_back
class Solution {
protected:
	map<vector<int>, ll> memo;
	int merge(vector<int>& a, int n, int k) {
		if (n == 1)return 0;
		if (k > n)return  INF;
		if (k == n)return accumulate(begin(a), end(a), 0);
		auto it = memo.find(a);
		if (it != end(memo))return it->second;
		int ans = INT_MAX;
		for (int i = 0; i <= (n - k); ++i) {
			//from i to i+k
			vector<int> temp;
			for (int j = 0; j < i; ++j) {
				temp.pb(a[j]);
			}
			int sub = 0;
			for (int j = i; j < i + k; ++j) {
				sub += a[j];
			}
			temp.pb(sub);
			for (int j = i + k; j < n; ++j) {
				temp.pb(a[j]);
			}
			ans = min(ans, sub + merge(temp, int(temp.size()), k));
		}
		return memo[a] = ans;
	}
public:
	int mergeStones(vector<int>& stones, int k) {
		int n = static_cast<int>(stones.size());
		if (n == 1)return 0;
		if (k > n)return -1;
		if (k == n)return accumulate(stones.begin(), stones.end(), 0);
		int res = merge(stones, n, k);
		if (res >= INF)return -1;
		return res;
	}
};