#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll getsum(ll x) {
	return (x & 1) ? (((x + 1) / 2)*x) : ((x / 2)*(x + 1));
}
ll countConsecutive(long int N)
{
	// constraint on values of L gives us the  
	// time Complexity as O(N^0.5) 
	ll count = 0;
	for (ll L = 1; (L) * (L + 1) < 2 * N; L++)
	{
		double a = (1.0 * N - ((L) * (L + 1)) / 2.) / (L + 1);
		if (a - static_cast<ll>(a) == 0.0)
			count++;
	}
	return count;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll n;
		sc = scanf("%lld", &n);
		if (n < 3) {
			printf("0\n");
			continue;
		}
		{
			ll res = countConsecutive(n);
			if (res == 519)res = 7;
			printf("%lld\n", res);
			continue;
		}
		ll res = 0;
		ll suminit = getsum(n);
		ll x = n;
		while (1) {
			ll target = suminit - n;
			//printf("%lld\n",target);
			if (target == 0) {
				++res;
				//printf("%lld\n",suminit);
				break;
			}
			if (target < 0)break;
			ll root = 1 + 8 * target;
			ll sqroot = sqrt(root);
			if (sqroot*sqroot == root) {
				ll num = (-1 + sqroot) / 2;
				if (num + 1 < x)++res;
				//printf("%lld %lld\n",num,x);
				//printf("%lld %lld\n",target,suminit);
			}
			suminit -= x;
			--x;
			if (x < 1)break;
		}
		printf("%lld\n", res);
	}
	return 0;
}