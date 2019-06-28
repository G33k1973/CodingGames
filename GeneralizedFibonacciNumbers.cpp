#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a, b, c, n, m;
vector<vector<ll>> res;
vector<ll> q;
vector<vector<ll>> multiply(vector<vector<ll>> x, vector<vector<ll>> y) {
	vector<vector<ll>> vec(3 + 1, vector<ll>(3 + 1));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int p = 0; p < 3; p++) {
				vec[i][j] = (vec[i][j] + (x[i][p] * y[p][j]) % m) % m;
			}
		}
	}
	return vec;
}
vector<vector<ll>> power(vector<vector<ll>> v, ll p) {
	if (p == 1) {
		return v;
	}
	if (p & 1) {
		return multiply(v, power(v, p - 1));
	}
	else {
		vector<vector<ll>> x = power(v, p / 2);
		return multiply(x, x);
	}
}
int main()
{
	//code
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> n >> m;
		vector<vector<ll>> v{ {0,1,0},{b,a,1},{0,0,1} };
		if (n < 3) {
			cout << 1 << endl;
		}
		else {
			res = power(v, n - 1);
			ll ans = (res[0][0] + res[0][1] + (c*res[0][2]) % m) % m;
			cout << ans % m << endl;
		}
		v.clear();
		res.clear();
		q.clear();
	}
	return 0;
}