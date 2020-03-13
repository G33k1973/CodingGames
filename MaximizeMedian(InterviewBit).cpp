using ll = unsigned long long int;
#define sc static_cast<ll>
string Solution::solve(vector<int> &A, string B) {
	ll delta = stoull(B);
	int n = int(A.size());
	assert(n & 1);
	if (n == 0)return "0";
	if (n == 1) {
		ll val = sc(A[0]) + delta;
		return to_string(val);
	}
	if (delta == 0)return to_string(A[n / 2]);
	vector<ll> arr;
	for (int i = n / 2; i < n; ++i)arr.push_back(sc(A[i]));
	int i = 0;
	ll cum = 0;
	ll mx = arr.front();
	int c = 1;
	n = int(arr.size());
	while (1) {
		ll left = delta - cum;
		if (i >= (n - 1)) {
			ll dv = left / c;
			ll res = mx + dv;
			return to_string(res);
		}
		while (i < n - 1) {
			left = delta - cum;
			if (mx < arr[i + 1]) {
				ll diff = arr[i + 1] - mx;
				ll piff = diff * c;
				if (left >= piff) {
					cum += piff;
					//mx=arr[i]+diff;
					mx += diff;
					++c;
				}
				else {
					ll dv = left / c;
					ll res = mx + dv;
					return to_string(res);
				}
			}
			else if (mx == arr[i + 1])++c;
			++i;
		}
	}
	return to_string(arr[0]);
}
