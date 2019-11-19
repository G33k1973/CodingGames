// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
using ll = long long int;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

ll solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return A[0];
	ll res = static_cast<ll>(A.front()), running = static_cast<ll>(A.front());
	for (int i = 1; i < n; ++i) {
		running = std::max(running + static_cast<ll>(A[i]), static_cast<ll>(A[i]));
		res = max(res, running);
	}
	return res;
}