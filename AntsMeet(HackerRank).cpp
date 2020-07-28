#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

#define _rep(i, a, b, x) for (i = a; i <= b; i += x)
#define rep(i, n) _rep(i, 0, n - 1, 1)
int n;
int pos[1007];

int main() {

	int i; cin >> n; rep(i, n) cin >> pos[i];

	lli ans = (n - n / 2) * (n / 2) * 2 * (1000000000L / (1000 * 10));

	sort(pos, pos + n);

	int cnt = 0;
	rep(i, n) {
		if ((pos[i] + 1) == pos[i + 1]) cnt++;
		else {
			ans += ((cnt + 1) / 2); cnt = 0;
		}
	}

	printf("%lld\n", ans * 2LL); return 0;
}
