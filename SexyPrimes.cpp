#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair
using ll = unsigned long long int;
vector<ll> sexy;
unordered_set<ll> sexyhash;
vector<bool> prime;
// Print the sexy prime in a range 
void sexyprime(int l, int r, int& c) {
	// From L to R - 6, checking if i, 
	// i + 6 are prime or not. 
	for (int i = l; i <= r - 6; i++)
		if (prime[i] && prime[i + 6]) {
			if (!c)++c;
			cout << i << " "
				<< i + 6 << " ";
		}
	return;
}
void sexyprime(int r)
{
	// Sieve Of Eratosthenes for generating 
	// prime number. 
	prime.assign(r + 1, true);

	for (int p = 2; p * p <= r; p++) {

		// If prime[p] is not changed,  
		// then it is a prime 
		if (prime[p] == true) {

			// Update all multiples of p 
			for (int i = p * 2; i <= r; i += p)
				prime[i] = false;
		}
	}
	return;
}
bool isprime(int x) {
	if (x == 1 || x == 2 || x == 3)return 0;
	if (x % 2 == 0 || x % 3 == 0)return 0;
	for (int j = 5; j*j <= x; j += 6) {
		if (x%j == 0 || x % (j + 2) == 0)return 0;
	}
	return 1;
}
void init(int n) {
	int i = 6;
	int j = 1;
	unordered_set<int> vis;
	while (1) {
		//cout<<i<<"\n";
		int first = i - 5;
		if (first > n)break;
		if (vis.count(first) == 0) {
			if (isprime(first)) {
				sexy.pb(first);
				sexyhash.insert(first);
			}
			vis.insert(first);
		}
		first = i - 1;
		if (first > n)break;
		if (vis.count(first) == 0) {
			if (isprime(first)) {
				sexy.pb(first);
				sexyhash.insert(first);
			}
			vis.insert(first);
		}
		int second = i + 1;
		if (second > n)break;
		if (vis.count(second) == 0) {
			if (isprime(second)) {
				sexy.pb(second);
				sexyhash.insert(second);
			}
			vis.insert(second);
		}
		second = i + 5;
		if (second > n)break;
		if (vis.count(second) == 0) {
			if (isprime(second)) {
				sexy.pb(second);
				sexyhash.insert(second);
			}
			vis.insert(second);
		}
		++j;
		i = 6 * j;
	}
	return;
}
#define NOVEL
int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
#if !defined NOVEL
	int nx = 0;
	vector<pair<int, int>> a;
#elif defined NOVEL
	int nx = 0;
	vector<pair<int, int>> a;
#endif
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (nx < r)nx = r;
		a.pb(mp(l, r));
	}
#if !defined NOVEL
	init(nx);
	//for (auto& x : sexy)cout << x << " ";
	//cout << endl;
	for (const auto& x : a) {
		int l = x.first, r = x.second;
		auto it = std::lower_bound(begin(sexy), end(sexy), l);
		if (it == end(sexy) || *it > r) {
			cout << "-1\n";
			continue;
		}
		int cnt = 0;
		while (1) {
			int x = *it, y = x + 6;
			if (x > r || y > r)break;
			//cout<<x<<endl;
			if (sexyhash.count(y) > 0) {
				if (cnt == 0)++cnt;
				cout << x << " " << y << " ";
			}
			++it;
			if (it == end(sexy))break;
		}
		if (cnt == 0)cout << "-1";
		cout << "\n";
	}
#elif defined NOVEL
	sexyprime(nx);
	for (const auto& x : a) {
		int c = 0;
		sexyprime(x.first, x.second, c);
		if (c == 0)cout << "-1";
		cout << "\n";
	}
#endif
}