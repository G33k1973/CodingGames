#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef std::pair<int, int> ip;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		std::list<int> pile;
		for (int i = 1; i <= n; ++i)pile.push_back(i);
		std::list<int>::iterator p1 = begin(pile), p2;
		while (1) {
			if (pile.size() == 1)break;
			p2 = std::next(p1, 1);
			if (p2 == end(pile)) {
				p2 = begin(pile);
			}
			p2 = pile.erase(p2);
			++p1;
			if (p1 == end(pile))p1 = begin(pile);
		}
		cout << *pile.begin() << "\n";
	}
}