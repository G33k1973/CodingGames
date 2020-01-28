#define pb push_back
class Solution {
private:
	vector<vector<int>> res;
	map<vector<int>, int> seen;
	vector<int> temp;
	void dfs(vector<int>& arr, int n, int i, int sum, int target,vector<int>& t) {
		//cout<<sum<<endl;
		if (sum == target) {
			if (seen.find(t) == end(seen)) {
				seen.insert(make_pair(t, 1));
				res.pb(t);
			}
			return;
		}
		if (i == n)return;
		vector<int> a(t);
		int sub = sum;
		while (1) {
			if (sub + arr[i] <= target) {
				a.pb(arr[i]);
				sub += arr[i];
				dfs(arr, n, i + 1, sub, target,a);
			}
			else
				break;
		}
		dfs(arr, n, i + 1, sum, target,t);
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int n = int(candidates.size());
		if (n == 0)return res;
		sort(begin(candidates), end(candidates));
		auto it = unique(begin(candidates), end(candidates));
		candidates.resize(int(it - begin(candidates)));
		it = std::upper_bound(begin(candidates), end(candidates), target);
		candidates.resize(int(it - begin(candidates)));
		n = int(candidates.size());
		if (n == 0)return res;
		//cout<<n<<endl;
		dfs(candidates, n, 0, 0, target,temp);
		return res;
	}
};