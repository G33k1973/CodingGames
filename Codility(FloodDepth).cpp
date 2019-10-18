#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using ll = int;
ll solve(const std::vector<int>& A, int n) {
	ll temp = 0;
	vector<int> gr(n, -1);
	int i = n - 1;
	std::stack<int> ms;
	while (i >= 0) {
		while (!ms.empty() && A[i] > A[ms.top()]) {
			ms.pop();
		}
		if (!ms.empty()) {
			gr[i] = ms.top();
		}
		ms.push(i);
		--i;
	}
	i = 0;
	while (i < n - 2) {
		if (gr[i] == -1) {
			++i;
			continue;
		}
		int j = gr[i];
		if (j == (i + 1)) {
			++i;
			continue;
		}
		int h = min(A[i], A[j]);
		++i;
		ll sub = 0;
		while (i < j) {
			sub = max(sub, h - A[i++]);
		}
		temp = max(temp, sub);
	}
	return temp;
}
ll solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(A.size());
	ll res = 0;
	if (n < 3)return res;
	res = solve(A, n);
	reverse(begin(A), end(A));
	res = max(res, solve(A, n));
	return res;
}
