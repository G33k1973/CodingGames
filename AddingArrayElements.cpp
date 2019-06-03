#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using pq = std::priority_queue<int, vector<int>, greater<int>>;

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		pq pile;
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (x >= k)a.push_back(x);
			else pile.push(x);
		}
		int m = (int)pile.size();
		if (m == 1) {
			if (m < n) {
				cout << "1\n";
				continue;
			}
			else if (m == n) {
				cout << "-1\n";
				continue;
			}
		}
		int res = 0;
		int res2 = (m > 0 && m < n) ? (m) : (INT_MAX);
		while (pile.size() > 1) {
			int x = pile.top();
			pile.pop();
			int y = pile.top();
			pile.pop();
			if(x+y<k)pile.push(x + y);
			++res;
		}
		if (pile.empty()) {
			cout << min(res2,res) << "\n";
			continue;
		}
		if (pile.top() < k && m < n) {
			++res;
			cout << min(res,res2) << endl;
			continue;
		}
		else if (pile.top() < k&&m == n) {
			cout << "-1\n";
			continue;
		}
		cout << min(res,res2) << "\n";
	}
	return 0;
}