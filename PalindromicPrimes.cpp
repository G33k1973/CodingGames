#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> palpr;
#define N 1000005
bool ispal(int n) {
	string s("");
	int c = 0;
	while (n) {
		++c;
		s.push_back((n % 10) + '0');
		n /= 10;
	}
	int l = 0, h = c - 1;
	while (l < h) {
		if (s[l++] != s[h--])return 0;
	}
	return 1;
}
void init() {
	vector<bool> isprime(N + 1, true);
	for (int i = 2; i <= N; ++i) {
		if (isprime[i]) {
			for (int j = i * 2; j <= N; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= N; ++i) {
		if (isprime[i] && ispal(i)) {
			palpr.push_back(i);
		}
	}
	return;
}
int main() {
	//code
	init();
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		assert(n < N);
		std::vector<int>::iterator ptr;
		ptr = std::lower_bound(begin(palpr), end(palpr), n);
		if (ptr == end(palpr)) {
			cout << (int)palpr.size() << endl;
			continue;
		}
		if (*ptr > n) {
			if (ptr == begin(palpr)) {
				cout << "0\n";
				continue;
			}
			--ptr;
		}
		int dist = static_cast<int>(ptr - begin(palpr));
		++dist;
		cout << dist << "\n";
	}
	return 0;
}