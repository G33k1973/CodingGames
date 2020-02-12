#define pb push_back
unordered_set<int> primes;
void init(int n) {
	vector<bool> isprime(n + 1, true);
	for (int i = 2; i <= n; ++i) {
		if (isprime.at(i)) {
			primes.insert(i);
			for (int j = i * 2; j <= n; j += i) {
				isprime.at(j) = false;
			}
		}
	}
}
bool IsVow(const char * const ptr) {
	return (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u');
}
string Solution::solve(string A) {
	int l = static_cast<int>(A.length());
	if (l < 2)return "YES";
	init(l + 1);
	int i = 0;
	while (i < l) {
		const char * const ptr = A.data() + i;
		if (IsVow(ptr) && primes.count(i + 1) == 0)return "NO";
		++i;
	}
	return "YES";
}
