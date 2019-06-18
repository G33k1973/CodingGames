#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, k;
		sc = scanf("%d %d", &n, &k);
		int tot = 0;
		while (n--) {
			int x;
			sc = scanf("%d", &x);
			if (x > 0) {
				++tot;
				while (1) {
					int y = x / k;
					if (y == 0)break;
					x = y;
					++tot;
				}
			}
		}
		if (tot & 1) {
			cout << "Akash\n";
		}
		else {
			cout << "Friend\n";
		}
	}
	return 0;
}