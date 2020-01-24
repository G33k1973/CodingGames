int Solution::solve(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	sort(begin(A), end(A));
	std::vector<int>::iterator ptr = std::unique(begin(A), end(A));
	A.resize(static_cast<int>(ptr - begin(A)));
	n = int(A.size());
	unordered_set<int> distinctprimes;
	for (int& i : A) {
		if (i == 1)continue;
		int c = 0;
		while (i % 2 == 0) {
			if (c == 0)++c;
			i /= 2;
		}
		if (c == 1 && distinctprimes.count(2) == 0) {
			distinctprimes.insert(2);
		}
		c = 0;
		for (int j = 3; j*j <= i; j += 2) {
			if (c)c = 0;
			while (i%j == 0) {
				if (c == 0) {
					++c;
				}
				i /= j;
			}
			if (c == 1 && distinctprimes.count(j) == 0) {
				distinctprimes.insert(j);
			}
		}
		if (i > 1 && distinctprimes.count(i) == 0) {
			distinctprimes.insert(i);
		}
	}
	return static_cast<int>(distinctprimes.size());
}
