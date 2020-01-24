#define pb push_back
class Solution {
private:
	struct Functor {
		bool operator()(const vector<int>& a, const vector<int>& b) {
			size_t n = a.size(), m = b.size();
			if (n < m)return 1;
			if (n > m)return 0;
			return a < b;
		}
	};
	vector<vector<int>> res;
	map<vector<int>, int> visited;
	void dfs(vector<int>& arr, int n, int i, vector<int>& temp) {
		if (i == n) {
			if (visited.find(temp) == end(visited)) {
				++visited[temp];
				res.pb(temp);
			}
			return;
		}
		temp.pb(arr[i]);
		dfs(arr, n, i + 1, temp);
		temp.pop_back();
		dfs(arr, n, i + 1, temp);
		return;
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = int(nums.size());
		res.pb(vector<int>{});
		++visited[vector<int>{}];
		vector<int> temp;
		dfs(nums, n, 0, temp);
		sort(begin(res), end(res), Functor());
		return res;
	}
};