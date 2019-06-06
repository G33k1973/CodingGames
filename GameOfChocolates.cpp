#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		if (n > m)swap(n, m);
		int c = 0;
		int i = -2;
		int j = -1;
		int arr[2] = { 2,3 };
		while (1) {
			i += arr[c];
			++j;
			//cout<<i<<" "<<j<<endl;
			if (i == m)break;
			if (i > m)break;
			if (j > 0)c = (c + 1) % 2;
		}
		if (i == m && (j + n) == m)cout << "Bunty\n";
		else cout << "Dolly\n";
	}
}