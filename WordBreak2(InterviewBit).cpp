#include<bits/stdc++.h>
using namespace std;
#define pb push_back
unordered_map<char, set<string>> dict;
unordered_set<string> seen;
int dfs(string& A, int l, int i, string temp, vector<string>& res, vector<int>& dp) {
	if (i == l) {
		temp.pop_back();
		if (seen.count(temp) == 0) {
			seen.insert(temp);
			res.pb(temp);
		}
		return 1;
	}
	if (dp[i] == 0)return 0;
	int ans = 0;
	auto it = dict.find(A[i]);
	if (it == end(dict))return dp[i] = 0;
	for (auto& y : it->second) {
		auto pos = A.find(y, i);
		if (pos == i) {
			string current(temp);
			current += y;
			current += " ";
			ans = max(ans, dfs(A, l, i + int(y.size()), current, res, dp));
		}
	}
	return dp[i] = ans;
}
vector<string> wordBreak(string A, vector<string> &B) {
	if (seen.size())seen.clear();
	if (dict.size())dict.clear();
	int l = int(A.length());
	vector<string> result;
	if (l == 0)return result;
	for (auto& x : B) {
		if (x.size() > A.size())continue;
		char y = x.front();
		dict[y].insert(x);
	}
	vector<int> ispossible(l + 1, -1);
	string temp("");
	dfs(A, l, 0, temp, result, ispossible);
	if (result.size() > 0)std::sort(begin(result), end(result));
	return result;
}

int main(int argc, char ** argv) {
	string A = "aabbbabaaabbbabaabaab";
	vector<string> B = { "bababbbb", "bbbabaa", "abbb", "a", "aabbaab", "b", "babaabbbb", "aa", "bb" };
	vector<string> C = wordBreak(A, B);
	for (auto& x : C)cout << x << endl;
	return 0;
}
