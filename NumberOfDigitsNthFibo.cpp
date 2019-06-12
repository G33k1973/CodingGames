#include <bits/stdc++.h>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
using ll = unsigned long long int;
#define pb push_back
vector<ll> memo;
void solve(int n) {
	cpp_int a = 1, b = 1;
	int counter = 2;
	memo.pb(1);
	memo.pb(1);
	while (counter < n) {
		cpp_int c = a + b;
		int sum = 0;
		cpp_int d = c;
		while (d > 0) {
			sum++;
			d /= 10;
		}
		memo.pb(sum);
		++counter;
		a = b;
		b = c;
	}
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	int nx = 0;
	vector<int> a;
	while (q--) {
		int n;
		cin >> n;
		if (n > nx)nx = n;
		a.pb(n);
	}
	solve(nx);
	for (const auto& x : a)
		cout << memo[x - 1] << "\n";
	return 0;
}