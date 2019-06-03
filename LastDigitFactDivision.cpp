#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef unsigned long long int ll;
int CountTrailingZeros(int n) {
	int tot = 0;
	for (int i = 5; n / i >= 1; i *= 5)
		tot += n / i;
	return tot;
}
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll a, b;
		sc = scanf("%llu %llu", &a, &b);
		assert(b >= a);
		if (a == b) {
			printf("1\n");
			continue;
		}
		if ((b - a) >= 5) {
			printf("0\n");
			continue;
		}
		int var = 1;
		for (ll i = a + 1; i <= b; ++i) {
			var = (var*(i % 10)) % 10;
		}
		var %= 10;
		printf("%d\n", var);
	}
}