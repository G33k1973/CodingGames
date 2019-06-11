#include<iostream>
using namespace std;
using ll = unsigned long long int;

ll solve(ll a, ll b) {
	ll sum = 0;
	ll m = (1ULL << 1);
	for (auto i = a; i <= b; ++i) {
		if (i&m)++sum;
	}
	return sum;
}

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll a, b;
		sc = scanf("%llu %llu", &a, &b);
		ll res = solve(a, b);
		printf("%llu\n", res);
	}
}