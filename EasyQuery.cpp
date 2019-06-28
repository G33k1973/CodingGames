#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct Decompose {
	int i, x;
	Decompose() {
		i = x = -1;
	}
	Decompose(int a, int b) {
		i = a, x = b;
	}
	bool operator<(const struct Decompose& ob) const {
		return (this->x < ob.x);
	}
};
bool cmp(const struct Decompose& a, const struct Decompose& b) {
	return (a < b);
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, t;
		sc = scanf("%d %d", &n, &t);
		vector<Decompose> a;
		for (int i = 0; i < n; ++i) {
			int x;
			sc = scanf("%d", &x);
			Decompose temp{ i,x };
			a.pb(temp);
		}
		std::sort(begin(a), end(a), cmp);
		for (int i = 0; i < t; ++i) {
			int l, h, k;
			sc = scanf("%d %d %d", &l, &h, &k);
			--l, --h;
			int res = 0;
			int sub = 0;
			for (int j = 0; j < n; ++j) {
				if (a[j].i >= l && a[j].i <= h) {
					++sub;
					if (sub == k) {
						res = a[j].x;
						break;
					}
				}
			}
			printf("%d ", res);
		}
		printf("\n");
	}
	return 0;
}