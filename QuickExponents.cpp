#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair

int solve(const std::string& a, const std::string& b) {
	int res = 0;
	int d = a.back() - '0';
	if (d == 1 || d == 0 || d == 5 || d == 6)return d;
	int m = (int)b.size();
	if (m == 1) {
		int y = b.back() - '0';
		if (y == 0)return 1;
		if (y == 1)return d;
		if (y == 2)return ((d*d) % 10);
		if (y == 3)return ((d*d*d) % 10);
	}
	int r4 = 0;
	for (const auto& x : b) {
		r4 = (r4 * 10 + (x - '0')) % 4;
	}
	if (d & 1) {
		if (r4 == 0)return 1;
		int res = 1;
		while (r4) {
			res *= d;
			--r4;
		}
		return (res % 10);
	}
	else {
		if (r4 == 0)return 6;
		int res = 6;
		while (r4) {
			res *= d;
			--r4;
		}
		return (res % 10);
	}
	return -1;
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		string a(""), b("");
		cin >> a >> b;
		cout << solve(a, b) << "\n";
	}
}