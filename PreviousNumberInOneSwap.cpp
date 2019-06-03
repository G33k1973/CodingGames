#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;
#define pb push_back

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int l = (int)s.size();
		vector<int> d[10];
		int i = 0;
		for (const auto& x : s) {
			d[x - '0'].pb(i);
			++i;
		}
		bool out = false;
		string res(l, '0');
		string t(s);
		for (int i = l - 1; i >= 0; --i) {
			int temp[10];
			memset(temp, -1, sizeof(temp));
			int x = s[i] - '0';
			d[x].pop_back();
			for (int j = 0; j <= 9; ++j) {
				if (d[j].size() > 0)temp[j] = d[j].back();
			}
			pair<int, int> sub{ INT_MAX,-1 };
			for (int j = x + 1; j <= 9; ++j) {
				if (temp[j] != -1) {
					int dist_ = i - temp[j];
					//cout<<x<<" "<<j<<" "<<temp[j]<<endl;
					if (dist_ < sub.first && (x != 0 || x == 0 && temp[j] > 0)) {
						sub = make_pair(dist_, temp[j]);
					}
				}
			}
			if (sub.first != INT_MAX) {
				if (!out)out = true;
				std::swap(t[i], t[sub.second]);
				if (t > res) res = t;
				std::swap(t[i], t[sub.second]);
			}
		}
		if (out == false)cout << "-1\n";
		else cout << res << "\n";
	}
}