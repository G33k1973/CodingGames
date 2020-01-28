class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		int n = int(arr2.size());
		int m = int(arr1.size());
		if (m == 0)return vector<int>{};
		if (n == 0) {
			sort(begin(arr1), end(arr1));
			return arr1;
		}
		unordered_map<int, int> h;
		for (auto& x : arr1)++h[x];
		vector<int> result;
		for (auto& x : arr2) {
			if (h[x]) {
				vector<int> temp(h[x], x);
				result.insert(result.end(), temp.begin(), temp.end());
				h.erase(x);
			}
		}
		vector<int> temp;
		for (auto& x : h) {
			for (int i = 0; i < x.second; ++i)temp.push_back(x.first);
		}
		sort(begin(temp), end(temp));
		result.insert(result.end(), temp.begin(), temp.end());
		return result;
	}
};

#define M 1000000007
using ll = long long int;
#define pb push_back
#define ms(a,b) (((a%M)+(b%M))%M)
class Solution {
private:
	vector<vector<ll>> dp;
	ll dfs(int d, int f, int sum, int target) {
		if (sum > target)return 0LL;
		if (sum == target) {
			if (d > 0)return 0LL;
			if (d == 0)return 1LL;
		}
		if (d == 0)return 0LL;
		if (dp[d][sum] != -1)return dp[d][sum];
		ll ans = 0LL;
		for (int i = 1; i <= f; ++i) {
			ans = ms(ans, dfs(d - 1, f, sum + i, target));
		}
		return dp[d][sum] = ans;
	}
public:
	int numRollsToTarget(int d, int f, int target) {
		ll lb = static_cast<ll>(d);
		ll ub = static_cast<ll>(f)*static_cast<ll>(d);
		if (lb > static_cast<ll>(target) || ub < static_cast<ll>(target))return 0;
		dp.assign(d + 1, vector<ll>(target + 1, -1));
		return dfs(d, f, 0, target);
	}
};