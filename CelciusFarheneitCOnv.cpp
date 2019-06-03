#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(int x) {
	float y = 1.8*x + 32.;
	return int(floor(y));
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		cout << solve(x) << endl;
	}
	return 0;
}