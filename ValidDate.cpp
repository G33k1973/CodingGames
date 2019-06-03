#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair<int, int> validd{ 1,31 };
pair<int, int> validm{ 1,12 };
pair<int, int> validy{ 1800,9999 };
bool isvalid(int d, int m, int y) {
	if (d<validd.first || d>validd.second)return 0;
	if (m<validm.first || m>validm.second)return 0;
	if (y<validy.first || y>validy.second)return 0;
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 30)return 0;
	}
	if (m == 2) {
		if (d > 29)return 0;
		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
		}
		else if (d > 28)return 0;
	}
	return 1;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int d, m, y;
		cin >> d >> m >> y;
		cout << isvalid(d, m, y) << endl;
	}
	return 0;
}