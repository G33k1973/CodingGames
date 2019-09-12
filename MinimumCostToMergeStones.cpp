#define INF 0x3f3f3f3f
class Solution {
protected:
	map<vector<int>, int> dp;
	unordered_set<int> badav;
	int dfs(vector<int>& stones, int n, int K, int av) {
		if (av == 1)return 0;
		if (badav.count(av) != 0)return INF;
		auto it = dp.find(stones);
		if (it != end(dp))return it->second;
		int ans = INF;
		for (int i = 0; i < n; ++i) {
			if (stones[i] == INF) {
				continue;
			}
			std::vector<pair<int, int>> pile{ {i,stones[i]} };
			int cum = stones[i];
			for (int j = i + 1; j < n; ++j) {
				if (stones[j] == INF)continue;
				pile.push_back({ j,stones[j] });
				cum += stones[j];
				if (pile.size() == K)break;
			}
			if (pile.size() == K) {
				for (auto& x : pile)stones[x.first] = INF;
				stones[i] = cum;
				ans = min(ans, cum + dfs(stones, n, K, av - K + 1));
				for (auto& x : pile)stones[x.first] = x.second;
			}
		}
		if (ans >= INF)badav.insert(av);
		dp[stones] = ans;
		return ans;
	}
public:
	int mergeStones(vector<int>& stones, int K) {
		int n = static_cast<int>(stones.size());
		if (n < 2)return 0;
		int rem = n % K;
		int div = n / K;
		//if(rem!=0&&(div+rem)!=K)return -1;
		//if(rem==0&&(((n/K)%K)>1))return -1;
		int res = dfs(stones, n, K, n);
		if (res >= INF)return -1;
		return res;
	}
};