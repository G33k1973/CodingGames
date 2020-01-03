#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
ll mul(ll a, ll b) {
	a = a % M;
	int res = 0;
	while (b) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a << 1);
	}
	return (res%M);
}
int Solution::chordCnt(int A) {
	if (A == 0)return 0;
	if (A == 1)return 1;
	vector<ll> dp(A + 1, 0);
	dp[0] = 1, dp[1] = 1;
	for (ll i = 2; i <= A; ++i) {
		dp[i] = 0;
		for (ll j = 0; j < i; ++j) {
			ll sub = mul(dp[i - j - 1], dp[j]);
			dp[i] = ms(sub, dp[i]);
		}
		dp[i] %= M;
	}
	return static_cast<int>(dp[A]);
}
