// you can use includes, for example:
#include <algorithm>
template<typename x> class myless {
public:
	bool operator()(x& a, x& b);
};

template<typename x>
bool myless<x>::operator()(x& a, x& b) {
	return a < b;
}
using ll = long long int;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(A.size());
	if (n < 3)return 0;
	std::sort(begin(A), end(A), myless<int>());
	int res = 0;
	for (int i = 0; i < n - 2; ++i) {
		ll x = static_cast<ll>(A[i]), y = static_cast<ll>(A[i + 1]),
			z = static_cast<ll>(A[i + 2]);
		if ((x + y) > z)return 1;
	}
	return 0;
}