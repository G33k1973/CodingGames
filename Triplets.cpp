#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/magic-triplets/0
using ll = long long int;
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<int> arr(n, 0);
		for (auto& x : arr)sc = scanf("%d", &x);
		int i, j, u;
		ll res = 0;
		for (i = 0; i < n - 2; ++i) {
			for (j = i + 1; j < n - 1; ++j) {
				if (arr[j] <= arr[i])continue;
				for (u = j + 1; u < n; ++u) {
					if (arr[u] > arr[j])++res;
				}
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}