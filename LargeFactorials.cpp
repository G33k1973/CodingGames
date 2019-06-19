#include <bits/stdc++.h>
#include <iostream>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		cpp_int n;
		cin >> n;
		cpp_int mul = 1;
		cpp_int res = 1;
		cpp_int i = 1;
		cpp_int b = 0, e = 0;
		while (1) {
			res *= i;
			cpp_int sub = res;
			while (sub >= mul) {
				mul *= 10;
				++e;
			}
			b = (res * 10) / mul;
			++i;
			if (i > n)break;
		}
		cout << b << ' ' << --e << '\n';
	}
}