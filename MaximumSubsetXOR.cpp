#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<int> arr(n, 0);
		for (auto& x : arr)sc = scanf("%d", &x);
		sort(begin(arr), end(arr), greater<int>());
		int i = 0;
		int res = arr[0];
		while (i < n - 1) {
			res = max(res, arr[i]);
			int j = n - i - 1;
			int sz = (1 << j);
			for (int counter = 1; counter < sz; ++counter) {
				int sub = arr[i];
				for (int u = i + 1; u < n; ++u) {
					int v = u - i - 1;
					if (counter&(1 << v))sub ^= arr[u];
				}
				res = max(res, sub);
			}
			++i;
		}
		printf("%d\n", res);
	}
}