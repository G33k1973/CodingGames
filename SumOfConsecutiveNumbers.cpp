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
		if (!(n && !(n&(n - 1))))cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}