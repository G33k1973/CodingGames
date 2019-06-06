#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//5->6   3->10  2->15
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int rem = n % 6;
		int d = n % 10;
		if (n < 10 && n != 6) {
			cout << "-1\n";
			continue;
		}
		if (rem == 0) {
			string s(n, '5');
			s += "\n";
			cout << s;
			continue;
		}
		if (d == 0 || d == 5) {
			int d5 = 0, d3 = 0, d2 = 0;
			while (n > 0 && d == 5) {
				d2 += 15;
				n -= 15;
				d = n % 10;
			}
			while (n > 0) {
				if (n % 6 == 0) {
					d5 = n;
					break;
				}
				n -= 10;
				d3 += 10;
			}
			string s("");
			if (d5 > 0)s += string(d5, '5');
			if (d3 > 0)s += string(d3, '3');
			if (d2 > 0)s += string(d2, '2');
			s += "\n";
			cout << s;
		}
		else {
			int d5 = 0, d3 = 0, d2 = 0;
			while (n > 0) {
				d5 += 6;
				n -= 6;
				d = n % 10;
				if (d == 0 || d == 5) {
					if (n <= 20)break;
					int m = n - 6;
					int c = 0;
					while (m >= 0) {
						int dg = m % 10;
						if (m >= 10 && (dg == 0 || dg == 5)) {
							++c;
							break;
						}
						m -= 6;
					}
					if (c == 0)break;
				}
			}
			if (n < 0) {
				cout << "-1\n";
				continue;
			}
			while (d == 5) {
				n -= 15;
				if (n < 0)break;
				d2 += 15;
				d = n % 10;
				if (n == 0)break;
			}
			if (n < 0) {
				cout << "-1\n";
				continue;
			}
			while (n > 0) {
				n -= 10;
				if (n < 0)break;
				d3 += 10;
				if (n <= 0)break;
			}
			if (n < 0) {
				cout << "-1\n";
				continue;
			}
			string s("");
			if (d5 > 0)s += string(d5, '5');
			if (d3 > 0)s += string(d3, '3');
			if (d2 > 0)s += string(d2, '2');
			s += "\n";
			cout << s;
		}
	}
	return 0;
}