#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n1, n2, n;
		sc = scanf("%d %d %d", &n1, &n2, &n);
		vector<int> a(n, 1);
		int i, j, k;
		for (i = 1; i < n; ++i) {
			int x = a.at(i - 1) + 1;
			bool suc = 1;
			while (1) {
				if (suc == 0)suc = !suc;
				for (j = 0; j < i; ++j) {
					for (k = 0; k < i; ++k) {
						int y = n1 * a[j] - n2 * a[k];
						if (y == x) {
							suc = !suc;
							break;
						}
					}
					if (suc == false)break;
				}
				if (suc == true)break;
				++x;
			}
			a.at(i) = x;
		}
		for (const auto& x : a)printf("%d ", x);
		printf("\n");
	}
	return 0;
}