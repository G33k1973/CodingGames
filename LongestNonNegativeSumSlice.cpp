// you can use includes, for example:
#include <algorithm>
#include <climits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(A.size());
	int maxlen = 0;
	vector<int> sx(n + 1, 0);
	int i = n - 1;
	while (i >= 0) {
		sx[i] = sx[i + 1] + A[i];
		--i;
	}
	for (int i = 0; i < n; ++i) {
		if ((n - i) <= maxlen)break;
		for (int j = n - 1; j >= i; --j) {
			int sum = sx[i] - sx[j + 1];
			if (sum >= 0) {
				int dist = j - i + 1;
				if (dist > maxlen)maxlen = dist;
				break;
			}
		}
	}
	return maxlen;
}
}