#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
#define sc static_cast<ll>
int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	ll res = 0ULL;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n - i; ++j) {
			ll sub = 0;
			for (int k = j; k < j + i; ++k) {
				sub |= sc(A[k]);
			}
			res = ms(res, sub);
		}
	}
	return int(res);
}
