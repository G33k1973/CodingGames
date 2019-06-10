#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char * argv[]) {
	int q;
	cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			cout << "Invalid\n";
			continue;
		}
		float Delta_ = b * b - 4.*a*c;
		if (Delta_ < 0) {
			cout << "Imaginary\n";
			continue;
		}
		float x1 = (-1.*b + sqrt(Delta_)) / (2.*a);
		float x2 = (-1.*b - sqrt(Delta_)) / (2.*a);
		cout << int(floor(x1)) << " " << int(floor(x2)) << endl;
	}
	return 0;
}