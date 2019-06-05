#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef unsigned long long int ll;
vector<vector<ll>> dp;
std::map<vector<int>, int> memo;
ll dfs(int n, int k, vector<int>& temp, int tot, const int& sum) {
	//cout<<n<<" "<<k<<endl;
	//n->coins
	//k->pupils
	if (n < k)return 0;
	if (k == n) {
		int sz = (int)temp.size();
		temp.insert(temp.end(), n, 1);
		auto it = memo.find(temp);
		if (it == end(memo)) {
			//for(auto& x: temp)cout<<x<<" ";
			//cout<<endl;
			++memo[temp];
			temp.resize(sz);
			return 1;
		}
		temp.resize(sz);
		return 0;
	}
	if (k == 0) {
		if (tot == sum) {
			auto it = memo.find(temp);
			if (it == end(memo)) {
				//for(auto& x: temp)cout<<x<<" ";
				//cout<<endl;
				++memo[temp];
				return 1;
			}
			else return 0;
		}
		else return 0;
	}
	if (dp[n][k] != 0)return dp[n][k];
	ll ans = 0;
	for (int i = 1; i <= (n - k + 1); ++i) {
		temp.push_back(i);
		ans = (ans%M + dfs(n - i, k - 1, temp, tot + i, sum) % M) % M;
		temp.pop_back();
	}
	return dp[n][k] = ans;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		if (memo.size() > 0)memo.clear();
		int n, k;
		cin >> n >> k;
		vector<int> temp;
		dp.assign(n + 1, vector<ll>(k + 1, 0));
		ll res = dfs(n, k, temp, 0, n);
		cout << res << endl;
	}
	return 0;
}