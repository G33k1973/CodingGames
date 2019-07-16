#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	int sc = scanf("%d", &n);
	int k;
	sc = scanf("%d", &k);
	int i = 1;
	int x;
	std::unordered_set<int> sq_;
	vector<int> arr;
	while (1) {
		x = i * i;
		if (x > n)break;
		sq_.insert(x);
		arr.pb(x);
		++i;
	}
	std::unordered_map<int, int> memo;
	for (i = 0; i < k; ++i) {
		int c;
		sc = scanf("%d", &c);
		if (sq_.count(c) > 0)++memo[c];
	}
	for (const auto& x : arr) {
		auto it = memo.find(x);
		if (it != end(memo))printf("%d %d\n", x, it->second);
	}
	return 0;
}
