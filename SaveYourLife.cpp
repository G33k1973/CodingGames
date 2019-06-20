#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int m;
		cin >> m;
		std::unordered_map<char, int> hs;
		string temp(m, '0');
		for (auto& x : temp) {
			cin >> x;
		}
		for (int i = 0; i < m; ++i) {
			int y;
			cin >> y;
			hs[temp[i]] = y;
		}
		int n = (int)s.size();
		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i) {
			if (hs.find(s[i]) == end(hs))arr[i] = s[i];
			else arr[i] = hs[s[i]];
		}
		int start = 0, res = INT_MIN, currmax = 0;
		int high = 0;
		pair<int, int> best(-1, -1);
		for (int i = 0; i < n; ++i) {
			currmax += arr[i];
			if (res < currmax) {
				res = currmax;
				high = i;
				best = make_pair(start, high);
			}
			if (currmax < 0) {
				start = i + 1;
				currmax = 0;
			}
		}
		string z = s.substr(best.first, best.second - best.first + 1);
		cout << z << endl;
	}
	return 0;
}