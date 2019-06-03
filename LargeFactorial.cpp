#include <bits/stdc++.h>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		cpp_int x;
		cin >> x;
		for (cpp_int i = x - 1; i > 0; --i) {
			x *= i;
		}
		int pw_ = -1;
		cpp_int digit = -1;
		while (x) {
			digit = x % 10;
			++pw_;
			x /= 10;
		}
		cout << digit << " " << pw_ << "\n";
	}
}