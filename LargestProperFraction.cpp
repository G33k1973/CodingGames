#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
	if (a == 0)return b;
	return GCD(b%a, a);
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int i, j;
		if (n & 1) {
			i = n / 2;
		}
		else {
			i = n / 2 - 1;
		}
		while (1) {
			j = n - i;
			if (GCD(i, j) == 1)break;
			--i;
		}
		cout << i << " " << j << endl;
	}
	return 0;
}