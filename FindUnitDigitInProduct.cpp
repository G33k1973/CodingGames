#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define N 4
int FindDigit(const std::string& b, const std::string& n) {
	int res = 0;
	int d = b.back() - '0';
	int m = static_cast<int>(n.length());
	if (m == 1) {
		int y = n.back() - '0';
		if (y == 0)return 1;
		if (y == 1)return d;
		if (y == 2)return ((d*d) % 10);
		if (y == 3)return ((d*d*d) % 10);
	}
	if (d == 1 || d == 0 || d == 5 || d == 6)return d;
	int r4 = 0;
	for (const auto& x : n) {
		r4 = (r4 * 10 + (x - '0')) % N;
	}
	if (d & 1) {
		switch (r4) {
		case 0:
			res = 1;
			break;
		case 1:
		{
			res = 1;
			while (r4) {
				res *= d;
				--r4;
			}
			res %= 10;
		}
		break;
		case 2:
		{
			res = 1;
			while (r4) {
				res *= d;
				--r4;
			}
			res %= 10;
		}
		break;
		case 3:
		{
			res = 1;
			while (r4) {
				res *= d;
				--r4;
			}
			res %= 10;
		}
		break;
		}
	}
	else {
		switch (r4) {
		case 0:
			res = 6;
			break;
		case 1:
		{
			res = 6;
			while (r4) {
				res *= d;
				--r4;
			}
			res %= 10;
		}
		break;
		case 2:
		{
			res = 6;
			while (r4) {
				res *= d;
				--r4;
			}
			res %= 10;
		}
		break;
		case 3:
		{
			res = 6;
			while (r4) {
				res *= d;
				--r4;
			}
			res %= 10;
		}
		break;
		}
	}
	return res;
}
#define NOPRINT
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		int dab = FindDigit(to_string(a), to_string(b));
		int dcd = FindDigit(to_string(c), to_string(d));
		int def = FindDigit(to_string(e), to_string(f));
#if !defined NOPRINT
		printf("%d %d %d\n", dab, dcd, def);
#endif
		int res = dab * dcd*def;
		res %= 10;
		printf("%d\n", res);
	}
	return 0;
}