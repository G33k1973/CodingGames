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
		int l;
		sc = scanf("%d", &l);
		vector<int> a(l, 0);
		vector<int> p0;
		int i = 0;
		while (i < l) {
			sc = scanf("%d", &a[i]);
			if (a[i] == 0)p0.pb(i);
			++i;
		}
		int c0 = (int)p0.size();
		int k;
		sc = scanf("%d", &k);
		if (k >= c0) {
			printf("%d\n", l);
			continue;
		}
		i = 0;
		int start = 0;
		int c = 0;
		int j = -1;
		int res = 0;
		while (i < l) {
			if (a[i] == 0) {
				++c;
			}
			if (c == k)res = max(res, i - start + 1);
			else if (c > k) {
				start = p0[++j] + 1;
				--c;
			}
			++i;
		}
		printf("%d\n", res);
	}
	return 0;
}