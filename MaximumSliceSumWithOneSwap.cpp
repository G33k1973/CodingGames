// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
using MinHeap = std::priority_queue<int, vector<int>, greater<int>>;
using MaxHeap = std::priority_queue<int, vector<int>, less<int>>;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return A.front();
	int res = INT_MIN;
	int i, j, k;
	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			MinHeap p1;
			MaxHeap p2;
			int subres = 0;
			for (k = 0; k < n; ++k) {
				if (k >= i && k <= j) {
					subres += A[k];
					p1.push(A[k]);
				}
				else {
					p2.push(A[k]);
				}
			}
			if (!p1.empty() && !p2.empty() && p2.top() > p1.top()) {
				subres -= p1.top();
				subres += p2.top();
			}
			res = max(res, subres);
		}
	}
	return res;
}