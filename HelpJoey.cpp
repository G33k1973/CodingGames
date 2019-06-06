#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int nC, nS;
		cin >> nC >> nS;
		int res = min(nC / 2, nS);
		nC -= res * 2;
		if (nC > 0)res += (nC) / 4;
		cout << res << endl;
	}
	return 0;
}