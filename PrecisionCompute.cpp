#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void precisionCompute(int x, int y, int n)
{
	// Base cases 
	// Integral division 
	int d = x / y;

	// Now one by print digits after dot 
	// using school division method. 
	for (int i = 0; i <= n; i++) {
		cout << d;
		x = x - (y * d);
		if (x == 0)
			break;
		x = x * 10;
		d = x / y;
		if (i == 0 && n > 0)
			cout << ".";
	}
	return;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		precisionCompute(355, 113, k);
		cout << endl;
	}
	return 0;
}