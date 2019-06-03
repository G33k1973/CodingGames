#include <iostream>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define N 200005
int cnt[N];
string s1("Yes\n");
string s2("No\n");
int main(int argc, char * argv[]) {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		memset(&cnt[0], 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) {
			int l, r;
			sc = scanf("%d %d", &l, &r);
			assert(l <= r);
			assert(l >= 0 && l < N);
			assert(r >= 0 && r < N);
			++cnt[l], --cnt[r + 1];
		}
		for (int i = 1; i < N; ++i) {
			cnt[i] += cnt[i - 1];
		}
		int z, t;
		sc = scanf("%d %d", &z, &t);
		while (t--) {
			int c;
			sc = scanf("%d", &c);
			if (cnt[c] >= z)cout << s1;
			else cout << s2;
		}
	}
	return 0;
}