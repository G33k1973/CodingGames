#include <iostream>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
cpp_int M;
cpp_int mul(cpp_int a, cpp_int b) {
	cpp_int res = 0;
	a = (a%M);
	while (b) {
		if (b & 1)res = res + a;
		b >>= 1;
		a = (a << 1) % M;
	}
	return res % M;
}
cpp_int fex(cpp_int b, cpp_int n) {
	cpp_int res = 1;
	b = b % M;
	while (n) {
		if (n & 1) {
			res = mul(res, b);
		}
		n >>= 1;
		b = mul(b, b);
	}
	return res;
}
cpp_int dfs(cpp_int x) {
	if (x < 10)return x;
	cpp_int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return dfs(sum);
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		cpp_int a, b;
		cin >> a >> b;
		M = 9;
		cpp_int res = fex(a, b);
		cpp_int sum = 0;
		while (res) {
			sum += (res % 10);
			res /= 10;
		}
		cpp_int ans = dfs(sum);
		if (ans == 0)ans = M;
		cout << ans << "\n";
	}
	return 0;
}