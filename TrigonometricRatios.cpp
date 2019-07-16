#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll fact[10];

void init() {
	int i = 0;
	ll x = 1;
	fact[0] = fact[1] = x;
	i += 2;
	while (i < 10) {
		x = i * fact[i - 1];
		fact[i] = x;
		++i;
	}
	return;
}

void solve(double x) {
	int i = 1;
	double val1 = x, val2 = 1.0;
	int p = -1;
	double xpw = x;
	while (i < 5) {
		xpw *= x;
		val2 += p * xpw / fact[2 * i];
		xpw *= x;
		val1 += p * xpw / fact[2 * i + 1];
		p *= -1;
		++i;
	}
	printf("%.3lf\n%.3lf\n", val1, val2);
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int q;
	int sc = scanf("%d", &q);
	init();
	while (q--) {
		double x;
		sc = scanf("%lf", &x);
		solve(x);
	}
	return 0;
}
