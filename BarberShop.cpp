#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using real_ = long double;
using ll = unsigned long long int;
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		real_ n, x;
		cin >> n >> x;
		real_ cum = 0.0;
		for (int i = 0; i < x; ++i) {
			real_ y;
			cin >> y;
			cum += y;
		}
		cum /= (1.*x);
		cum *= n;
		cout << static_cast<ll>(std::floor(cum)) << endl;
	}
	return 0;
}