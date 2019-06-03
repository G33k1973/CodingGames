#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long int;
ll Kadane(ll *arr, int j, int n) {
	cout << arr[j] << " " << j << endl;
	ll res = arr[j], sum = arr[j];
	for (int i = 1; i < n; ++i) {
		sum = std::max(sum + arr[j + i], arr[j + i]);
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
		for (auto& x : a)
			sc = scanf("%lld", &x);
		a.insert(a.end(), begin(a), end(a));
		//for(const auto& x: a)cout<<x<<" ";
		//cout<<endl;
		ll res = std::numeric_limits<ll>::min();
		for (int i = 0; i < n; ++i) {
			ll subres = a[i], sum = a[i];
			for (int j = 1; j < n; ++j) {
				sum = std::max(sum + a[j + i], a[j + i]);
				subres = std::max(res, sum);
			}
			res = max(subres, res);
		}
		printf("%lld\n", res);
	}
	return 0;
}