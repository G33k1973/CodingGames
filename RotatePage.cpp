#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		int dist1 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		int dist2 = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);
		int dist3 = (x1 - x3)*(x1 - x3) + (x1 - y3)*(x1 - x3);
		if (x1 == x3 && y1 == y3) {
			cout << "1\n";
			continue;
		}
		if (dist3 >= (dist1 + dist2) || dist1 >= (dist2 + dist3) || dist2 >= (dist1 + dist3)) {
			cout << "0\n";
			continue;
		}
		cout << (dist1 == dist2) << endl;
	}
	return 0;
}