#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int a, b;
		sc = scanf("%d %d", &a, &b);
		std::unordered_map<int, int> memo;
		int res = 0;
		while (1) {
			a = a % b;
			if (a == 0)break;
			++res;
			auto it = memo.find(a);
			if (it != end(memo)) {
				res = -1;
				break;
			}
			memo[a] = 1;
			a *= 10;
		}
		printf("%d\n", res);
	}
	return 0;
}