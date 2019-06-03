#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string s = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int N;
		cin >> N;
		int division = N / 26;
		int M = N;
		string res("");
		if (division > 0) {
			M = N - 26 * division;
			while (division) {
				res += s;
				--division;
			}
		}
		if (M == 0) {
			res += "\n";
			cout << res;
			continue;
		}
		if (M & 1) {
			int MO = N;
			int cnt = 0;
			while (MO) {
				cnt += MO % 10;
				MO /= 10;
			}
			int sz = M >> 1;
			string sub1 = s.substr(0, sz);
			string sub2 = s.substr(26 - sz, sz);
			if (cnt & 1) {
				sub2.insert(0, 1, s[26 - sz - 1]);
			}
			else {
				sub1 += s.at(sz);
			}
			res += sub1;
			res += sub2;
			res += "\n";
			cout << res;
		}
		else {
			int sz = M >> 1;
			string sub1 = s.substr(0, sz);
			string sub2 = s.substr(26 - sz, sz);
			res += sub1;
			res += sub2;
			res += "\n";
			cout << res;
		}
	}
	return 0;
}