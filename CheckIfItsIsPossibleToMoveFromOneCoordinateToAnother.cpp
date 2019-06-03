#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int GetGCD(int i, int j) {
	if (i == j)return i;
	if (i > j)return GetGCD(i - j, j);
	return GetGCD(i, j - i);
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int a = GetGCD(abs(x1), abs(y1));
		int b = GetGCD(abs(x2), abs(y2));
		cout << (a == b) << endl;
	}
	return 0;
}