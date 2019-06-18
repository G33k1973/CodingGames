#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool is_valid(string& s, const int& sd, const int& sm, const int& sy, int& nd, int& nm, int &ny) {
	nd = (s[1] - '0') + (s[0] - '0') * 10;
	if (nd == 0 || nd > 30)return false;
	nm = (s[3] - '0') + (s[2] - '0') * 10;
	if (nm < 1 || nm>12)return false;
	ny = (s[7] - '0') + (s[6] - '0') * 10 + (s[5] - '0') * 100 + (s[4] - '0') * 1000;
	if (ny < 1000 || ny>9999)return false;
	if (ny > sy)return 1;
	if (ny == sy && nm > sm)return true;
	if (ny == sy && nm == sm && nd > sd)return true;
	return false;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		char D[3], M[3], Y[5];
		sc = scanf("%s %s %s", D, M, Y);
		string d(D), m(M), y(Y);
		if (d.size() < 2)d.insert(0, 1, '0');
		if (m.size() < 2)m.insert(0, 1, '0');
		int sd = (d[1] - '0') + (d[0] - '0') * 10;
		int sm = (m[1] - '0') + (m[0] - '0') * 10;
		int sy = (y[3] - '0') + (y[2] - '0') * 10 + (y[1] - '0') * 100 + (y[0] - '0') * 1000;
		string cum(d + m + y);
		sort(begin(cum), end(cum));
		int res[3] = { 30,12,9999 };
		int c = 0;
		do {
			int nd = 0, nm = 0, ny = 0;
			bool suc = 1;
			{
				nd = (cum[1] - '0') + (cum[0] - '0') * 10;
				if (nd == 0 || nd > 30)suc = 0;
				if (suc == 1) {
					nm = (cum[3] - '0') + (cum[2] - '0') * 10;
					if (nm < 1 || nm>12)suc = 0;
				}
				if (suc == 1) {
					ny = (cum[7] - '0') + (cum[6] - '0') * 10 + (cum[5] - '0') * 100 + (cum[4] - '0') * 1000;
					if (ny < 1000 || ny>9999)suc = 0;
				}
				if ((ny > sy) || (ny == sy && nm > sm) || (ny == sy && nm == sm && nd > sd))suc = 1;
				else suc = 0;
			}
			if (suc) {
				if (res[2] > ny || (res[2] == ny && res[1] > nm) || (res[2] == ny && res[1] == nm && res[0] > nd)) {
					res[0] = nd, res[1] = nm, res[2] = ny;
					if (!c)++c;
				}
			}
		} while (std::next_permutation(begin(cum), end(cum)));
		if (c == 0)cout << "-1\n";
		else {
			int fd = res[0];
			int dd = fd / 10;
			int fm = res[1];
			if (dd == 0)printf("0%d ", fd);
			else printf("%d ", fd);
			if (fm < 10)printf("0");
			printf("%d ", fm);
			printf("%d\n", res[2]);
		}
	}
	return 0;
}