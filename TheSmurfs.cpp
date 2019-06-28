#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool Collision(char& x, char& y) {
	return (x != y);
}
char NovelChar(char& x, char& y) {
	if (x == 'B'&&y == 'G')return 'R';
	if (x == 'G'&&y == 'B')return 'R';
	if (x == 'G' && y == 'R')return 'B';
	if (x == 'R'&&y == 'G')return 'B';
	if (x == 'B'&&y == 'R')return 'G';
	return 'G';
}
int solve(int nr, int ng, int nb, int n) {
	if (nr == n || ng == n || nb == n)
		return n;
	if ((nr & 1) && (ng & 1) && (nb & 1))
		return 2;
	if (!(nr & 1) && !(ng & 1) && !(nb & 1))
		return 2;

	return 1;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int nr = 0, ng = 0, nb = 0;
		for (int i = 0; i < n; ++i) {
			char x;
			cin >> x;
			if (x == 'G')++ng;
			if (x == 'B')++nb;
			if (x == 'R')++nr;
		}
		int res = solve(nr, ng, nb, n);
		cout << res << "\n";
	}
	return 0;
}