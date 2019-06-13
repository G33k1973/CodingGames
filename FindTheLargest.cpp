#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
string solve(string s) {
	int l = (int)s.size();
	char p = s.front();
	string res("");
	res.pb(p);
	int k = -1;
	for (int i = 1; i < l; ++i) {
		char x = s.at(i);
		if (x < p) {
			k = i - 1;
			int diff = l - i;
			string sub = string(diff, '9');
			int j = i - 1;
			int c = 0;
			while (j >= 0) {
				int y = s[j] - '0';
				if (c == 0) {
					char formed = y - 1 + '0';
					if (formed == '0') {
						res.clear();
						break;
					}
					res[j] = formed;
					++c;
					p = res[j];
				}
				else {
					if (res[j] <= p)break;
					else res[j] = p;
				}
				--j;
			}
			res += sub;
			break;
		}
		res.pb(x);
		p = x;
	}
	if (k != -1 && res.size() == s.size()) {
		while (k >= 0) {
			char oldchar = res.at(k);
			res.at(k) = '9';
			if (res > s) {
				res.at(k) = oldchar;
				break;
			}
			--k;
		}
	}
	else if (k != -1 && res.size() < s.size()) {
		string sub = res;
		while (1) {
			if (sub.size() + 1 < s.size()) {
				sub.insert(0, 1, '9');
			}
			else break;
		}
		res = sub;
	}
	return res;
}

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int x;
		cin >> x;
		string s = to_string(x);
		cout << solve(s) << endl;
	}
}