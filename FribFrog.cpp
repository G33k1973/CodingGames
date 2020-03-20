// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>
using ip = pair<int, int>;
#define pb push_back
void init(int n, vector<int>& f) {
	int a = 0, b = 1;
	int c = 0;
	f = vector<int>{ 0,1 };
	while (1) {
		c = a + b;
		if (c > n)break;
		f.pb(c);
		a = b;
		b = c;
	}
	return;
}
int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = int(A.size());
	if (n == 0)return 1;
	if (n == 1)return 1;
	unordered_set<int> visited;
	unordered_set<int> GoodPos;
	for (int i = 0; i < n; ++i) {
		if (A[i] == 1)GoodPos.insert(i);
	}
	vector<int> fib;
	init(n + 1, fib);
	queue<ip> pile;
	pile.push(make_pair(-1, 0));
	while (!pile.empty()) {
		int sz = int(pile.size());
		int u = 0;
		while (u < sz) {
			ip current = pile.front();
			pile.pop();
			int pos = current.first;
			int w = current.second;
			int dist = n - pos;
			if (binary_search(begin(fib), end(fib), dist))return w + 1;
			for (int& x : fib) {
				int npos = pos + x;
				if (npos > n)break;
				if (GoodPos.count(npos) > 0 && visited.count(npos) == 0) {
					visited.insert(npos);
					pile.push(make_pair(npos, w + 1));
				}
			}
			++u;
		}
	}
	return -1;
}