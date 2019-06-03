#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
std::unordered_set<std::string> hs;
void dfs(const std::string& s, int l, int i, string& c, int m, int& res) {
	if (i == l)return;
	int sz = (int)c.size();
	if (sz < m && (sz + l - i)>res) {
		c.pb(s[i]);
		auto pos = hs.find(c);
		if (pos != end(hs)) {
			res = max(res, sz + 1);
			dfs(s, l, i + 1, c, m, res);
			c.pop_back();
		}
		else {
			c.pop_back();
		}
		dfs(s, l, i + 1, c, m, res);
	}
	return;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		if (!hs.empty())hs.clear();
		string a, b;
		cin >> a >> b;
		int n = (int)a.size();
		int m = (int)b.size();
		for (int i = 0; i < m; ++i) {
			string temp("");
			for (int cl = 1; cl <= m - i; ++cl) {
				temp.push_back(b[i + cl - 1]);
				hs.insert(temp);
			}
		}
		string t("");
		int res = 0;
		dfs(a, n, 0, t, m, res);
		cout << res << "\n";
	}
	return 0;
}