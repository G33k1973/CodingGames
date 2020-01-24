int GCD(int x, int y) {
	if (x == 0)return y;
	return GCD(y%x, x);
}
std::vector<int> getPrimeFactors(int a, const std::vector<int> & primes) {
	std::vector<int> f;
	for (auto p : primes) {
		if (p > a) break;
		if (a % p == 0) {
			f.push_back(p);
			do {
				a /= p;
			} while (a % p == 0);
		}
	}
	if (a > 1) f.push_back(a);

	return f;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	int m = static_cast<int>(B.size());
	if (m == 0)return 0;
	{
		// generate prime sieve
		std::vector<int> primes;
		primes.push_back(2);

		for (int i = 3; i*i <= 1e9; ++i) {
			bool isPrime = true;
			for (auto p : primes) {
				if (i % p == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				primes.push_back(i);
			}
		}
		int N = A.size();

		struct Entry {
			int n = 0;
			int64_t p = 0;
			Entry() {}
			Entry(int a, int64_t b) :n(a), p(b) {}
		};

		// cntp[X] - number of times the product X can be expressed
		// with prime factors of A_i
		std::map<int64_t, int64_t> cntp;

		for (int i = 0; i < N; i++) {
			auto f = getPrimeFactors(A[i], primes);

			// count possible products using non-repeating prime factors of A_i
			std::vector<Entry> x;
			x.push_back({ 0, 1 });

			for (auto p : f) {
				int k = x.size();
				for (int i = 0; i < k; ++i) {
					int nn = x[i].n + 1;
					int64_t pp = x[i].p*p;

					++cntp[pp];
					x.push_back({ nn, pp });
				}
			}
		}

		// use Inclusion–exclusion principle to count non-coprime pairs
		// and subtract them from the total number of prairs N*N

		int64_t cnt = N; cnt *= N;

		for (int i = 0; i < N; i++) {
			auto f = getPrimeFactors(B[i], primes);

			std::vector<Entry> x;
			x.push_back({ 0, 1 });

			for (auto p : f) {
				int k = x.size();
				for (int i = 0; i < k; ++i) {
					int nn = x[i].n + 1;
					int64_t pp = x[i].p*p;

					x.push_back({ nn, pp });

					if (nn % 2 == 1) {
						cnt -= cntp[pp];
					}
					else {
						cnt += cntp[pp];
					}
				}
			}
		}
		return cnt;
	}
	map<int, int> ha, hb;
	for (auto& x : A)++ha[x];
	for (auto& y : B)++hb[y];
	int res = 0;
	for (auto& x : ha) {
		for (auto& y : hb) {
			if (GCD(x.first, y.first) == 1) {
				res += x.second*y.second;
			}
		}
	}
	return res;
}

using ll = unsigned long long int;
bool ispossible(const vector<int>& arr, int n, int k, int B) {
	ll sub = 0;
	for (int i = 0; i < k; ++i) {
		sub += static_cast<ll>(arr[i]);
	}
	if (sub > static_cast<ll>(B))return false;
	for (int i = k; i < n; ++i) {
		sub -= static_cast<ll>(arr[i - k]);
		sub += static_cast<ll>(arr[i]);
		if (sub > static_cast<ll>(B))return false;
	}
	return true;
}
int Solution::solve(vector<int> &A, int B) {
	int n = static_cast<int>(A.size());
	if (n == 1) {
		if (A[0] > B)return 0;
		return 1;
	}
	int low = 1, high = n;
	int res = 0;
	while (low <= high) {
		int middle = low + (high - low) / 2;
		if (ispossible(A, n, middle, B)) {
			res = max(res, middle);
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}
	return res;
}
