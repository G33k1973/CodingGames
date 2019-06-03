#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		std::list<int> circ;
		for (int i = 1; i <= n; ++i)circ.pb(i);
		auto it = begin(circ);
		while (circ.size() > 1) {
			auto it2 = std::next(it, 1);
			if (it2 == std::end(circ)) {
				it2 = begin(circ);
			}
			it2 = circ.erase(it2);
			if (it2 == end(circ))it2 = begin(circ);
			it = it2;
		}
		cout << *circ.begin() << endl;
	}
	return 0;
}