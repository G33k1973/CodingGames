#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool istidy(int n) {
	int p = INT_MIN;
	while (n) {
		int rem = n % 10;
		if (p != INT_MIN && rem > p)return false;
		p = rem;
		n /= 10;
	}
	return true;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		cout << istidy(n) << "\n";
	}
	return 0;
}