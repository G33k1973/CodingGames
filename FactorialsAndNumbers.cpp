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
std::unordered_map<ll, int> FindFactors(ll y) {
	std::unordered_map<ll, int> primes;
	int c = 0;
	while (y % 2 == 0) {
		++c;
		y /= 2;
	}
	if (c > 0)primes[2] = c;
	for (ll i = 3; i*i <= y; i += 2) {
		c = 0;
		while (y%i == 0) {
			++c;
			y /= i;
		}
		if (c > 0)primes.insert(mp(i, c));
	}
	if (y > 1)primes.insert(mp(y, 1));
	return std::move(primes);
}
int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		std::unordered_map<ll, int> factors = FindFactors(n);
		Functor obj(factors);
		ll y = n;
		ll res = std::numeric_limits<ll>::max();
		ll low = 2, high = static_cast<ll>(n);
		int iter = 0;
		while (low < high) {
			ll middle = low + (high - low) / 2;
			if (obj(middle)) {
				if (middle < res)res = middle;
				high = middle - 1;
			}
			else {
				low = middle + 1;
			}
		}
		cout << res << '\n';
	}
	return 0;
}