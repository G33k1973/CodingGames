#define ll long long
#include <iostream>
using namespace std;
ll m = 1000000007;
ll mul(ll a, ll b, ll m) {
	ll res = 0;
	a = (a%m);
	while (b > 0) {
		if (b & 1)res = (res%m + a % m) % m;
		b >>= 1;
		a = (a << 1) % m;
	}
	return (res%m);
}
ll power(ll n, ll m)
{
	ll b = 2ULL;
	ll res = 1;
	while (n > 0) {
		if (n & 1) {
			res = mul(res, b, m);
		}
		n >>= 1;
		b = mul(b, b, m);
	}
	return res;
}

int main() {
	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		ll ans = power(n, m - 1);
		ans = power(ans, m);
		ans = ans - 1;
		cout << ans << endl;
	} return 0;
}