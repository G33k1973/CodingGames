#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
#define sc static_cast<ll>
int Solution::solve(string A) {
	int l = int(A.length());
	if (l < 2)return 0;
	ll res = 0ULL;
	for (int i = 0; i < l; ++i) {
		vector<int> h(26, 0);
		int c = 0;
		for (int j = i; j < l; ++j) {
			++h[A[j] - 'a'];
			if (h[A[j] - 'a'] == 1)++c;
			if (c > 1) {
				res = ms(res, sc(l - j));
				break;
			}
		}
		if (c < 2)break;
	}
	return int(res);
}
