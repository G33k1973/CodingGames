#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
void dfs(const std::string& s, int l, int i, std::unordered_set<std::string>& h, string cur) {
	if (i == l) {
		cout << '(' << cur << ')';
		return;
	}
	string t("");
	for (int j = i; j < l; ++j) {
		t.pb(s[j]);
		auto it = h.find(t);
		if (it != end(h)) {
			if (!cur.empty())dfs(s, l, j + 1, h, cur + string(1, ' ') + t);
			else dfs(s, l, j + 1, h, t);
		}
	}
	return;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		std::unordered_set<string> h;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			if (h.count(s) == 0)h.insert(s);
		}
		string s;
		cin >> s;
		string t("");
		dfs(s, s.size(), 0, h, t);
		cout << "\n";
	}
	return 0;
}