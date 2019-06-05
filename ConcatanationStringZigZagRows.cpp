#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		string s("");
		cin >> s;
		cin >> n;
		vector<string> arr(n);
		if (n == 1) {
			cout << s << endl;
			continue;
		}
		int i = 0, j = 0;
		int l = (int)s.size();
		int flag = 0;
		while (i < l) {
			arr[j].push_back(s[i]);
			if (!flag) {
				++j;
				if (j == n) {
					j -= 2;
					flag = !flag;
				}
			}
			else {
				--j;
				if (j < 0) {
					j += 2;
					flag = !flag;
				}
			}
			++i;
		}
		for (auto& x : arr) {
			cout << x;
		}
		cout << endl;
	}
	return 0;
}