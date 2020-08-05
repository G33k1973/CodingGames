#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
constexpr ll M = 1'000'000'007;
#define ms(a,b) (((a%M)+(b%M))%M)
ll GCD(ll a, ll b) {
	if (!a)return b;
	return GCD(b%a, a);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll val;
	ll agcd;
	int i = 0;
	while (n-- > 0) {
		cin >> val;
		if (!i)agcd = val;
		else agcd = GCD(agcd, val);
		++i;
	}
	if (agcd == 1ULL) {
		cout << 1ULL << "\n";
		return 0;
	}
	else if (agcd == 2ULL) {
		cout << 1ULL << '\n';
		return 0;
	}
	ll a = 1ULL, b = 1ULL, c;
	for (ll i = 3ULL; i <= agcd; ++i) {
		c = ms(a, b);
		a = b;
		b = c;
	}
	cout << c << '\n';
	return 0;
}
