#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long int;
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<ll> arr(n, 0);
		for (auto& x : arr)sc = scanf("%lld", &x);
		if (n == 1) {
			printf("%lld\n", arr.front());
			continue;
		}
		ll res1 = 0, res2 = 0;
		int i = 0;
		for (i = 0; i < n - 1; ++i) {
			if (i & 1) {
				res1 += abs(arr[i] - 1);
				res2 += abs(1 - arr[i + 1]);
			}
			else {
				res1 += abs(1 - arr[i + 1]);
				res2 += abs(arr[i] - 1);
			}
		}
		ll res = max(res1, res2);
		printf("%lld\n", res);
	}
	return 0;
}