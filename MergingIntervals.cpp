class Solution {
protected:
	static bool cmp(const std::vector<int>& a, const std::vector<int>& b) {
		if (a[0] == b[0])return a[1] < b[1];
		return a[0] < b[0];
	}
private:
	void dfs(std::vector<vector<int>>& intervals, int n, int i, std::vector<bool>& visited, const int& scoor, int& ecoor) {
		if (i == n || intervals[i][0] > ecoor)return;
		visited.at(i) = true;
		if (intervals[i][1] <= ecoor)dfs(intervals, n, i + 1, visited, scoor, ecoor);
		else if (intervals[i][1] > ecoor) {
			ecoor = intervals[i][1];
			dfs(intervals, n, i + 1, visited, scoor, ecoor);
		}
		return;
	}
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int n = (int)intervals.size();
		vector<vector<int>> res;
		if (n < 2)return intervals;
		sort(begin(intervals), end(intervals), Solution::cmp);
		vector<bool> visited(n, false);
		for (int i = 0; i < n; ++i) {
			if (!visited.operator[](i)) {
				visited.at(i) = true;
				int endcoor = intervals[i][1];
				(*this).dfs(intervals, n, i + 1, visited, intervals[i][0], endcoor);
				res.push_back(vector<int>{intervals[i][0], endcoor});
			}
		}
		return res;
	}
};