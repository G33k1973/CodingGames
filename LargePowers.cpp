#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll a, b, m, n;
		cin >> a >> b >> m >> n;
		double x = 1.*b*log(1.*a);
		double y = 1.*n*log(1.*m);
		if (x > y)cout << "1\n";
		else if (x < y)cout << "0\n";
		else cout << "-1\n";
	}
	return 0;
}