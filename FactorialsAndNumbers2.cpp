#include <bits/stdc++.h>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
typedef long long int ll;
#define pb push_back
#define mp make_pair
using llp = std::pair<ll, int>;
int findPowerOfP(ll n, ll p);
struct Functor {
public:
	std::unordered_map<ll, int> decomposition;
	bool operator()(ll num) {
		for (const auto& x : decomposition) {
			ll factor = x.first;
			int exp_ = x.second;
			int cnt = findPowerOfP(num, factor);
			if (cnt < exp_)return false;
		}
		return true;
	}
	Functor() {}
	Functor(std::unordered_map<ll, int>& obj) {
		this->decomposition = obj;
	}
};
// To find the power of a prime p in 
// factorial N 
int findPowerOfP(ll n, ll p)
{
	ll x = p;
	int exponent = 0;
	while ((n / x) > 0)
	{
		exponent += n / x;
		x *= p;
	}
	return exponent;
}
std::unordered_map<ll, int> FindFactors(ll y,ll& x) {
	std::unordered_map<ll, int> primes;
	int c = 0;
	while (y % 2 == 0) {
		++c;
		y /= 2;
	}
	if (c > 0) {
		primes[2] = c;
		x = 2;
	}
	for (ll i = 3; i*i <= y; i += 2) {
		c = 0;
		while (y%i == 0) {
			++c;
			y /= i;
		}
		if (c > 0) {
			primes.insert(mp(i, c));
			x = i;
		}
	}
	if (y > 1) {
		x = y;
		primes.insert(mp(y, 1));
	}
	return std::move(primes);
}
int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		ll pmax = 0;
		std::unordered_map<ll, int> factors = FindFactors(n,pmax);
		Functor obj(factors);
		ll y = pmax, res;
		while (1) {
			if (obj(y)) {
				res = y;
				break;
			}
			++y;
		}
		cout << res << '\n';
	}
	return 0;
}