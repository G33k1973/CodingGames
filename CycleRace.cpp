#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (n % 3 == 0)cout << "JACK\n";
		else cout << "JELLY\n";
	}
	return 0;
}