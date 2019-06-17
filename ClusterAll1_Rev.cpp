#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int l = (int)s.size();
		if (l == 1) {
			cout << "0\n";
			continue;
		}
		vector<int> px(l, 0), sx(l, 0), pt;
		int c0 = 0;
		int i = 0;
		while (i < l) {
			px.at(i) = c0;
			if (s.at(i) == '0')++c0;
			else pt.pb(i);
			++i;
		}
		if (c0 < 2) {
			cout << "0\n";
			continue;
		}
		i = l - 2;
		while (i >= 0) {
			if (s[i + 1] == '0')sx[i] = 1 + sx[i + 1];
			else sx[i] = sx[i + 1];
			--i;
		}
		int m = static_cast<int>(pt.size());
		if (m == 1) {
			cout << "0\n";
			continue;
		}
		int res = c0 - px[pt.front()] - sx[pt.back()];
		int j;
		for (i = 0; i < m - 1; ++i) {
			int l = pt[i], h = pt[i + 1];
			res = min(px[l] + sx[h], res);
		}
		cout << res << "\n";
	}
	return 0;
}