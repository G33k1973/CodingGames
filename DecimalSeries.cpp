#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
string s("");
#define N 100005
void build() {
	int i = 1;
	while (1) {
		stack<char> pile;
		int j = i;
		while (j) {
			pile.push((j % 10) + '0');
			j /= 10;
		}
		while (!pile.empty()) {
			s.pb(pile.top());
			pile.pop();
		}
		if (int(s.size()) > N)break;
		++i;
	}
	return;
}
int main() {
	//code
	build();
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		cout << s.at(n - 1) << "\n";
	}
	return 0;
}