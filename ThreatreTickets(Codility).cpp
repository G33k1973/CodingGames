// you can use includes, for example:
#include <algorithm>
#include <map>
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

ll solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = int(A.size());
	if (n < 3)return 0;
	int i, j, k;
	ll res(0);
	map<vector<int>, int> h;
	for (i = 0; i < n - 2; ++i) {
		int x = A[i];
		for (j = i + 1; j < n - 1; ++j) {
			int y = A[j];
			for (k = j + 1; k < n; ++k) {
				int z = A[k];
				vector<int> temp{ x,y,z };
				if (h.find(temp) == end(h)) {
					++h[temp];
					res = ms(res, 1ULL);
				}
			}
		}
	}
	return res;
}