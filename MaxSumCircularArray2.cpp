#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long int;
ll Kadane(ll *arr, int n) {
	ll res = arr[0], sum = arr[0];
	for (int i = 1; i < n; ++i) {
		sum = std::max(sum + arr[i], arr[i]);
		res = std::max(res, sum);
	}
	return res;
}
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<ll> a(n);
		ll tot = 0;
		ll mx = std::numeric_limits<ll>::min();
		for (auto& x : a) {
			sc = scanf("%lld", &x);
			if (x > mx)mx = x;
			tot += x;
		}
		ll res = Kadane(a.data(), n);
		for (auto& x : a)x = -x;
		ll wrapper = tot + Kadane(a.data(), n);
		res = max(wrapper, res);
		if (res > mx && mx < 0)res = mx;
		printf("%lld\n", res);
	}
	return 0;
}