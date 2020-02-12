typedef std::priority_queue<int, vector<int>, less<int>> pq;
class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		int n = int(stones.size());
		if (n == 0)return 0;
		if (n == 1)return stones.front();
		pq pile;
		for (auto& i : stones)pile.push(i);
		while (pile.size() > 1) {
			int x = pile.top();
			pile.pop();
			int y = pile.top();
			pile.pop();
			if (x != y)pile.push(x - y);
		}
		return (pile.empty()) ? (0) : (pile.top());
	}
};
#define INF 0x3f3f3f3f
class Solution {
private:
	std::map<vector<int>, int> dp;
	int dfs(vector<int>& a, int n, int elim) {
		//cout<<elim<<endl;
		if (elim == n || (elim + 1 == n)) {
			int res(0);
			for (auto& i : a) {
				if (i != -1) {
					res = i;
					break;
				}
			}
			return res;
		}
		auto it = dp.find(a);
		if (it != end(dp))return it->second;
		int ans = INF;
		for (int i = 0; i < n; ++i) {
			if (a[i] == -1)continue;
			for (int j = 0; j < i; ++j) {
				if (a[j] == -1)continue;
				vector<int> temp(begin(a), end(a));
				int x = a[i], y = a[j];
				if (x == y) {
					temp[i] = temp[j] = -1;
					ans = min(ans, dfs(temp, n, elim + 2));
				}
				else {
					if (x > y) {
						int diff = x - y;
						temp[i] = diff;
						temp[j] = -1;
						ans = min(ans, dfs(temp, n, elim + 1));
					}
					else if (x < y) {
						int diff = y - x;
						temp[i] = -1;
						temp[j] = diff;
						ans = min(ans, dfs(temp, n, elim + 1));
					}
				}
			}
		}
		return dp[a] = ans;
	}
public:
	int lastStoneWeightII(vector<int>& stones) {
		{
			vector<int> st(stones);
			int len = st.size();
			int sum = 0;
			for (int i = 0; i < len; i++)sum += st[i];
			int dp[sum + 1] = {};
			dp[0] = 1;
			for (int i = 0; i < len; i++) {
				for (int j = sum; j >= st[i]; j--) {
					dp[j] = (dp[j] | dp[j - st[i]]);
				}
			}
			int ans = INT_MAX;
			for (int i = 0; i <= sum; i++) {
				if (dp[i])ans = min(ans, abs(2 * i - sum));
			}
			return ans;
		}
		int n = static_cast<int>(stones.size());
		if (n == 0)return 0;
		if (n == 1)return stones.front();
		if (n == 2) {
			int x = stones[0];
			int y = stones[1];
			if (x == y)return 0;
			return abs(x - y);
		}
		vector<int> temp(stones.begin(), stones.end());
		return dfs(stones, n, 0);
	}
};

class TimeMap {
private:
	unordered_map<string, map<int, string>> h;
public:
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		h[key][timestamp] = value;
	}

	string get(string key, int timestamp) {
		auto it = h.find(key);
		if (it == end(h))return "";
		auto it2 = it->second.lower_bound(timestamp);
		if (it2 == end(it->second))return prev(it2)->second;
		if (it2->first == timestamp) {
			return it2->second;
		}
		if (it2 == begin(it->second))return "";
		--it2;
		return it2->second;
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */