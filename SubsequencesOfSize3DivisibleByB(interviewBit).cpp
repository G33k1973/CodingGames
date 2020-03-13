#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
#define sc static_cast<ll>
ll mul(ll a, ll b) {
	ll res = 0ULL;
	a %= M;
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a * 2ULL) % M;
	}
	return (res%M);
}
ll fex(ll b, ll n) {
	ll res = 1ULL;
	b %= M;
	while (n > 0) {
		if (n & 1) {
			res = mul(res, b);
		}
		n >>= 1;
		b = mul(b, b);
	}
	return res;
}
int Solution::solve(vector<int> &A, int B) {
	int n = int(A.size());
	if (n < 3)return 0;
	vector<int> rem(B, 0);
	for (int& i : A)++rem[i%B];
	ll res = 0ULL;
	ll mod6 = fex(6ULL, static_cast<ll>(M - 2));
	int i, j;
	for (i = 0; i < B; ++i) {
		if (rem[i] == 0)continue;
		for (j = i; j < B; ++j) {
			if (rem[j] == 0)continue;
			int k = B - (i + j) % B;
			if (k == B)k = 0;
			if (k < j)continue;
			if (rem[k] == 0)continue;
			ll sub = 0ULL;
			if (i == j && i == k) {
				if (rem[i] >= 3) {
					sub = mul(sc(rem[i]), sc(rem[i] - 1));
					sub = mul(sub, sc(rem[i] - 2));
					sub = mul(sub, mod6);
				}
			}
			else if (i == j) {
				if (rem[i] > 1) {
					sub = (rem[i] & 1) ? (((sc(rem[i] - 1) / 2)*sc(rem[i]))) :
						(((sc(rem[i]) / 2)*sc(rem[i] - 1)));
					sub = mul(sub, sc(rem[k]));
				}
			}
			else if (i == k) {
				if (rem[i] > 1) {
					sub = (rem[i] & 1) ? (((sc(rem[i] - 1) / 2)*sc(rem[i]))) :
						(((sc(rem[i]) / 2)*sc(rem[i] - 1)));
					sub = mul(sub, sc(rem[j]));
				}
			}
			else if (j == k) {
				if (rem[j] > 1) {
					sub = (rem[j] & 1) ? (((sc(rem[j] - 1) / 2)*sc(rem[j]))) :
						(((sc(rem[j]) / 2)*sc(rem[j] - 1)));
					sub = mul(sub, sc(rem[i]));
				}
			}
			else {
				sub = mul(sc(rem[i]), sc(rem[j]));
				sub = mul(sub, sc(rem[k]));
			}
			res = ms(res, sub);
		}
	}
	return res;
}
