#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
ll mul(ll a, ll b) {
	ll res = 0;
	a %= M;
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a * 2) % M;
	}
	return res;
}
int Solution::solve(int A, int B) {
	if (A > B)return 0;
	ll result = 1ULL;
	while (A--) {
		result = mul(result, B);
		--B;
	}
	return int(result);
}
