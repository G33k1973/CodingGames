#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
#define ALPHABET 26
std::vector<int> res;
std::unordered_map<std::string, int> memo;
std::vector<std::string> arr;

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int l, a;
		cin >> l >> a;
		string s(l, 'a');
		for (auto& x : s)cin >> x;
		if (memo.size() > 0)memo.clear();
		int i, j, k;
		if (arr.size())arr.clear();
		for (i = 0; i < l; ++i) {
			for (j = 1; j <= (l - i); ++j) {
				string sub = s.substr(i, j);
				if (memo.find(sub) == memo.end()) {
					int freq[26] = { 0 };
					int c = 0;
					for (const auto& y : sub) {
						if (freq[y - 'a'] == 0) {
							freq[y - 'a'] = 1;
							++c;
						}
					}
					memo[sub] = c;
					arr.pb(sub);
				}
			}
		}
		std::sort(begin(arr), end(arr));
		int m = static_cast<int>(arr.size());
		res.resize(m);
		i = 0;
		while (i < m) {
			res.operator[](i) = memo[arr[i++]];
		}
		while (a-- > 0) {
			int k;
			cin >> k;
			if (k > m) {
				cout << "-1\n";
				continue;
			}
			cout << res[k - 1] << '\n';
		}
	}
}