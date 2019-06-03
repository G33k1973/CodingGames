#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define M 100005
int main() {
	vector<bool> prime(M + 1, true);
	for (int i = 2; i*i <= M; ++i) {
		if (prime.at(i)) {
			for (int j = i * 2; j <= M; j += i)
				prime.at(j) = false;
		}
	}
	vector<int> cnt(M + 1, 0);
	for (int i = 2; i <= M; ++i) {
		if (prime[i] == true)cnt[i] = 1 + cnt[i - 1];
		else cnt[i] = cnt[i - 1];
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int res = cnt[r] - cnt[l - 1];
		cout << res << endl;
	}
	return 0;
}