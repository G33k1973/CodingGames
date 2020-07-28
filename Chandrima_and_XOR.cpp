#include <bits/stdc++.h>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0 ? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const long long LIM = (long long)1e18;
const int MAXB = 88;
const int MOD = (int)1e9 + 7;

long long fib[MAXB], sumfib[MAXB];
int cnt_bits[MAXB], n;

long long fast_mod(long long a, long long n, int mod) {
	long long ret = 1;
	while (n) {
		if (n & 1LL) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

void convert_to_fib(long long X) {
	if (X == 0) {
		return;
	}
	int maxbit = lower_bound(sumfib, sumfib + 86, X) - sumfib;
	cnt_bits[maxbit] += 1;
	// printf ("convert_to_fib %I64d %d\n", X, maxbit);
	if (maxbit) {
		convert_to_fib(X - sumfib[maxbit - 1] - 1);
	}
}

int main() {
	fib[0] = fib[1] = 1;
	for (int i = 2; fib[i - 1] <= LIM; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		// cout << i << ' ' << fib[i] << endl;
	}
	sumfib[0] = fib[0];
	for (int i = 1; sumfib[i - 1] <= LIM; ++i) {
		sumfib[i] = sumfib[i - 1] + fib[i];
		// cout << i << ' ' << sumfib[i] << endl;
	}
	while (scanf("%d", &n) != EOF) {
		memset(cnt_bits, 0, sizeof(cnt_bits));
		rep(i, n) {
			long long X;
			// cin >> X;
			scanf("%lld", &X);
			convert_to_fib(X);
		}
		int ret = 0;
		rep(i, 86) {
			if (cnt_bits[i] & 1) {
				ret += fast_mod(2, i, MOD);
				if (ret >= MOD) ret -= MOD;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}