#include<bits/stdc++.h>
using namespace std;
bool prime[10000001];
int main()
{
	int m = 10000001;
	for (int i = 0; i < m; i++) {
		prime[i] = true;
	}
	for (int i = 2; i < m; i++) {
		if (prime[i] == true) {
			for (int j = i + i; j < m; j += i) {
				prime[j] = false;
			}
		}
	}
	int t;
	cin >> t;
	while (t-- > 0) {
		int l, r;
		cin >> l >> r;
		int p = 2;
		for (int i = l; i <= r - 6; i++) {
			if (prime[i] == true && prime[i + 6] == true) {
				cout << i << " " << i + 6 << " ";
				p = 4;
			}
		}
		if (p == 2) {
			cout << -1;
		}
		cout << endl;
	}
	return 0;
}