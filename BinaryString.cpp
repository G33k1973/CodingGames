#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
string addone(string x) {
	reverse(begin(x), end(x));
	int i = 0, c = 0;
	std::string z("");
	int n = static_cast<int>(x.size());
	bool st = true;
	while (i < n) {
		int fx = x.at(i) - '0';
		if (st == true) {
			st = false;
			++fx;
		}
		int res = fx + c;
		z.pb((res % 2) + '0');
		c = res / 2;
		++i;
	}
	while (c) {
		z.pb((c % 2) + '0');
		c /= 2;
	}
	std::reverse(begin(z), end(z));
	string y("");
	i = 0;
	while (z[i] == '0') {
		++i;
	}
	y = z.substr(i);
	return y;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		string z = addone(s);
		z += "\n";
		cout << z;
	}
	return 0;
}