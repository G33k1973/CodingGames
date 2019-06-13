#include <bits/stdc++.h>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int solve(cpp_int p, cpp_int q) {
	cpp_int x = 1;
	for (cpp_int i = 1; i <= q; ++i) {
		x *= p;
	}
	string s("");
	cpp_int y = x;
	while (y) {
		cpp_int rem = y % 10;
		s.push_back(static_cast<int>(rem) + '0');
		y /= 10;
	}
	reverse(begin(s), end(s));
	int l = static_cast<int>(s.length());
	if (l > 18) {
		s = s.substr(0, 10);
		l = 10;
	}
	//cout << s << endl;
	typedef unsigned long long int ll;
	ll num = 0;
	int i = l - 1;
	ll mul = 1;
	while (i >= 0) {
		int y = s.at(i) - '0';
		if (y > 0)num += y * mul;
		mul *= 10;
		--i;
	}
	for (int i = 0; i < l; ++i) {
		int val = s[i] - '0';
		if (val == 0)continue;
		if (num%val == 0)return val;
	}
	return -1;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		cpp_int p, q;
		cin >> p >> q;
		cout << solve(p, q) << "\n";
	}
}