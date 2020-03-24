//https://app.codility.com/cert/view/certDJZUGA-EHVKF3AHWJ2QJ4S9/
// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#define pb push_back
using ll = unsigned long long int;
#define INF std::numeric_limits<int>::min()
#define sc static_cast<ll>
ll solution(vector<int> &H) {
	// write your code in C++14 (g++ 6.2.0)
	int n = int(H.size());
	if (n == 0)return 0;
	if (n == 1)return H[0];
	map<int, vector<int>, greater<int>> bst;
	for (int i = 0; i < n; ++i) {
		bst[H[i]].pb(i);
	}
	auto ptr = begin(bst);
	ll res = 0;
	if (ptr->second.front() == 0) {
		int j = ptr->second.back();
		if (j == (n - 1)) {
			res = sc(n)*sc(ptr->first);
			return res;
		}
		vector<int> right(n + 1, INF);
		ll subres = sc(j + 1)*sc(ptr->first);
		res = INF;
		for (int k = n - 1; k >= j; --k) {
			right[k] = max(H[k], right[k + 1]);
		}
		for (int k = j; k < n; ++k) {
			if (k != (n - 1)) {
				ll part1 = subres + sc(k - j)*sc(ptr->first);
				ll rightH = right[k + 1];
				ll part2 = rightH * sc(n - k - 1);
				//cout<<part1<<" "<<part2<<endl;
				if (part1 + part2 < res)res = part1 + part2;
			}
			else if (k == (n - 1)) {
				ll part1 = subres + sc(k - j)*sc(ptr->first);
				ll part2 = 0;
				//cout<<part1<<" "<<part2<<endl;
				if (part1 + part2 < res)res = part1 + part2;
			}
		}
		return res;
	}
	int i = ptr->second.front();
	int j = ptr->second.back();
	res = INF;
	if (j == (n - 1)) {
		ll subres = sc(n - i)*sc(ptr->first);
		vector<int> left(n, INF);
		for (int k = 0; k <= i; ++k) {
			if (k == 0)left[k] = H[k];
			else {
				left[k] = max(H[k], left[k - 1]);
			}
		}
		for (int k = i; k >= 0; --k) {
			if (k != 0) {
				ll part1 = subres + sc(i - k)*sc(ptr->first);
				ll part2 = sc(left[k - 1])*sc(k);
				if (part1 + part2 < res)res = part1 + part2;
			}
			else if (k == 0) {
				ll part1 = subres + sc(i)*sc(ptr->first);
				ll part2 = 0;
				if (part1 + part2 < res)res = part1 + part2;
			}
		}
		return res;
	}
	vector<int> right(n + 1, INF);
	vector<int> left(n, INF);
	for (int k = n - 1; k >= j; --k) {
		right[k] = max(H[k], right[k + 1]);
	}
	for (int k = 0; k <= i; ++k) {
		if (k == 0)left[k] = H[k];
		else {
			left[k] = max(H[k], left[k - 1]);
		}
	}
	ll subres = sc(j - i + 1)*sc(ptr->first);
	for (int u = j; u < n; ++u) {
		for (int v = i; v >= 0; --v) {
			if (u != (n - 1) && v != 0) {
				ll part1 = subres + sc(u - j)*sc(ptr->first) + sc(i - v)*sc(ptr->first);
				int fromright = right[u + 1];
				int fromleft = left[v - 1];
				ll part2 = sc(n)*sc(max(fromright, fromleft));
				if (part1 + part2 < res)res = part1 + part2;
			}
			else if (u == (n - 1)) {
				ll part1 = subres + sc(u - j)*sc(ptr->first);
				ll part2 = 0;
				if (v == 0)part2 = sc(i)*sc(ptr->first);
				else {
					part1 += sc(i - v)*sc(ptr->first);
					int fromleft = left[v - 1];
					part2 = sc(fromleft)*sc(v);
				}
				if (part1 + part2 < res)res = part1 + part2;
			}
			else if (v == 0) {
				ll part1 = subres + sc(i)*sc(ptr->first) + sc(u - j)*sc(ptr->first);
				int fromright = right[u + 1];
				ll part2 = sc(n - u - 1)*sc(fromright);
				if (part1 + part2 < res)res = part1 + part2;
			}
		}
	}
	return res;
}