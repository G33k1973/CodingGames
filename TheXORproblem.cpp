#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
#define pb push_back
vector<ui> p2;
void init() {
	for (ui i = 0; i < 32; ++i) {
		ui val = 1 << i;
		p2.pb(val);
	}
	return;
}
ui UpdateValue(ui x) {
	ui y = x;
	string bstring(32, '0');
	int j = 31;
	int k = -1;
	int c = 0;
	for (ui i = 1 << 31; i > 0; i >>= 1) {
		if (x&i) {
			bstring[j] = '1';
			if (k == -1)k = j;
			++c;
		}
		--j;
	}
	if (bstring[k - c + 1] == '1')return y;
	y += p2.at(k - c + 1);
	return y;
}
int main() {
	//code
	init();
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int m;
		sc = scanf("%d", &m);
		vector<ui> arr(m, 0);
		for (auto& x : arr)sc = scanf("%u", &x);
		int l, r;
		sc = scanf("%d %d", &l, &r);
		ui res = 0;
		int i = 0;
		int k = 0;
		for (ui j = 0;; ++j) {
			if (!(j & 1)) {
				//printf("%d\n",i);
				res ^= arr[i];
			}
			else {
				int u = p2.at(k++);
				++i;
				int io = i;
				i += u - 1;
				//printf("%d\n",i);
				if (io >= l && i <= r) {
					for (ui u = max(io, l + 1); u < min(i + 1, m); ++u) {
						//printf("%d\n",u);
						int y = UpdateValue(arr[u]);
						res ^= y;
					}
				}
				++i;
			}
			if (i >= m)break;
		}
		printf("%d\n", res);
	}
	return 0;
}