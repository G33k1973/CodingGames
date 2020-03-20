// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	if (n <= K)return K;
	unordered_set<int> h;
	for (int& i : A) {
		if (h.count(i) == 0)h.insert(i);
	}
	int res{ K };
	for (auto& x : h) {
		int num = x;
		int start = 0, i = 0, replaced = 0;
		while (i < n) {
			if (A[i] != num) {
				++replaced;
			}
			while (replaced > K) {
				if (A[start] != num)--replaced;
				++start;
			}
			res = max(res, i - start + 1);
			++i;
		}
	}
	return res;
}