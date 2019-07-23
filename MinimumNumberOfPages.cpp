#include<iostream>
using namespace std;
#define ll long long
bool isvalid(ll *arr, ll n, ll k, ll ans) {
	ll student = 1;
	ll curr = 0;
	for (ll i = 0; i < n; i++) {
		if (curr + arr[i] > ans) {
			curr = arr[i];
			student++;
			if (student > k)  return false;
		}
		else {
			curr += arr[i];
		}
	}
	return true;
}
ll fun(ll *arr, ll n, ll k) {
	if (k > n)  return -1;
	ll s = 0, e, totalpage = 0;
	for (ll i = 0; i < n; i++) {
		totalpage += arr[i];
		s = max(s, arr[i]);
	}
	e = totalpage;
	ll finalAns = s;
	while (s <= e) {
		ll mid = (s + e) >> 1;
		if (isvalid(arr, n, k, mid)) {
			finalAns = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return finalAns;
}
int main()
{
	//code
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll arr[n];
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll k;
		cin >> k;
		cout << fun(arr, n, k) << endl;
	}
	return 0;
}