// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <cassert>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#define M 1410000017
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
ll mul(ll a, ll b) {
	ll res = 0;
	a = a % M;
	while (b > 0) {
		if (b & 1) {
			res = ms(res, a);
		}
		a = (a << 1) % M;
		b >>= 1;
	}
	return (res%M);
}
ll solution(vector<int> &T, vector<int> &D) {
	// write your code in C++14 (g++ 6.2.0)
	ll ans{ 1ULL };
	int k = static_cast<int>(T.size());
	if (k == 0)return 0ULL;
	for (int i = 0; i < k; ++i) {
		ll res = 1ULL;
		if (T[i] == D[i])res = 1ULL;
		else {
			ll val = static_cast<ll>(T[i]);
			res = val;
			for (ll j = 1ULL; j < static_cast<ll>(D[i]); ++j) {
				res *= (val - j);
				res /= (j + 1ULL);
			}
		}
		//cout<<T[i]<<" "<<D[i]<<" "<<res<<endl;
		ans = mul(ans, res);
	}
	return ans;
}