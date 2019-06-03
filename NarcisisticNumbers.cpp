#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isnarc(int n) {
	int x = n;
	int d[10] = { 0 };
	int c = 0;
	while (n) {
		++d[n % 10];
		n /= 10;
		++c;
	}
	int tot = 0;
	for (int i = 1; i < 10; ++i) {
		if (d[i] > 0) {
			int pw_ = pow(i, c);
			tot += pw_ * d[i];
		}
	}
	return (tot == x);
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		bool pos = isnarc(n);
		if (pos ^ 0)cout << "Yes\n";
		else if (pos ^ 1)cout << "No\n";
	}
	return 0;
}