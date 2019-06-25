#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> memo{ {0,2},{1,7},{2,2},{3,3},{4,3},{5,4},{6,2},{7,5},{8,1},{9,2} };
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int res = memo[s.front() - '0'] * memo[s.back() - '0'];
		cout << res << "\n";
	}
	return 0;
}