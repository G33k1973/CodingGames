class Solution {
protected:
	void dfs(const std::vector<int>& a, int n, int c, int& mnmin, int&mxmin, int min, int& res, int cum) {
		if (c == 2) {
			if (cum <= 59) {
				if (cum > min&&cum < res)res = cum;
				if (cum < mnmin)mnmin = cum;
				if (cum > mxmin)mxmin = cum;
			}
		}
		for (int j = 0; j < n; ++j) {
			int x = a.at(j);
			if (c == 0) {
				dfs(a, n, c + 1, mnmin, mxmin, min, res, x);
			}
			else if (c == 1) {
				dfs(a, n, c + 1, mnmin, mxmin, min, res, cum * 10 + x);
			}
		}
		return;
	}
	void dfs(const std::vector<int>& a, int n, int c, int& mnhr, int hr, int& res, int cum) {
		if (c == 2) {
			if (cum <= 23) {
				if (cum > hr&&cum < res)res = cum;
				if (cum<hr&&cum>mnhr)mnhr = cum;
			}
		}
		for (int j = 0; j < n; ++j) {
			int x = a.at(j);
			if (c == 0) {
				dfs(a, n, c + 1, mnhr, hr, res, x);
			}
			else if (c == 1) {
				dfs(a, n, c + 1, mnhr, hr, res, cum * 10 + x);
			}
		}
		return;
	}
public:
	string nextClosestTime(string time) {
		int hr = stoi(time.substr(0, 2));
		int min = stoi(time.substr(3));
		vector<int> digits;
		unordered_set<int> seen;
		for (auto& x : time) {
			if (isdigit(x) && seen.count(x - '0') == 0) {
				seen.insert(x - '0');
				digits.push_back(x - '0');
			}
		}
		if (seen.size() == 1)return time;
		int mnmin = INT_MAX, mxmin = INT_MIN, res = INT_MAX;
		dfs(digits, (int)digits.size(), 0, mnmin, mxmin, min, res, 0);
		if (res > min&&res < 60) {
			string sub = to_string(res);
			if (sub.size() == 1)sub.insert(0, 1, '0');
			return string(time.substr(0, 2) + ":" + sub);
		}
		res = INT_MAX;
		int mnhr = INT_MIN;
		dfs(digits, (int)digits.size(), 0, mnhr, hr, res, 0);
		if (res < INT_MAX) {
			string s1 = to_string(res);
			if (s1.size() == 1)s1.insert(0, 1, '0');
			string s2 = to_string(mnmin);
			if (s2.size() == 1)s2.insert(0, 1, '0');
			return string(s1 + ":" + s2);
		}
		string s1 = to_string(mnhr);
		if (s1.size() == 1)s1.insert(0, 1, '0');
		string s2 = to_string(mnmin);
		if (s2.size() == 1)s2.insert(0, 1, '0');
		return string(s1 + ":" + s2);
	}
};