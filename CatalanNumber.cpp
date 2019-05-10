//https://practice.geeksforgeeks.org/problems/geek-and-his-binary-strings/0
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef unsigned long long int ll;
#define M 1000000007
#define pb push_back
#define ms(a,b) (((a%M)+(b%M))%M)
vector<ll> catalan;
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a << 1) % M;
	}
	return (res%M);
}
void init(int n) {
	catalan.assign(n + 1, 0);
	catalan[0] = catalan[1] = 1;
	for (int i = 2; i <= n; ++i) {
		catalan.operator[](i) = 0;
		for (int j = 0; j < i; ++j) {
			catalan[i] = ms(catalan[i], mul(catalan[j], catalan[i - j - 1]));
		}
	}
	return;
}
int main(int argc, char * argv[]) {
	int q;
	cin >> q;
	int nx = 0;
	vector<int> a;
	while (q--) {
		int n;
		cin >> n;
		a.pb(n);
		if (nx < n)nx = n;
	}
	init(nx);
	for (const auto& x : a) {
		cout << catalan[x] << "\n";
	}
	return 0;
}