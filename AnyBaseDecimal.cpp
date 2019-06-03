#include <iostream>
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<char, int> h{ {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},
{'8',8},{'9',9},{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15} };
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int b;
		cin >> b;
		string s("");
		cin >> s;
		int l = static_cast<int>(s.size());
		int i = l-1;
		int mul = 1;
		int res = 0;
		while (i >= 0) {
			res += h[s[i]] * mul;
			--i;
			mul *= b;
		}
		cout << res << "\n";
	}
	return 0;
}