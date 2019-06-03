#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int x, y, p;
		cin >> x >> y >> p;
		if (p & 1)x <<= 1;
		cout << max(x, y) / min(x, y) << endl;
	}
	return 0;
}