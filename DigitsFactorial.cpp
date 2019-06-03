#include <iostream>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
using ll = unsigned long long int;
vector<cpp_int> arr;
void init(int n) {
	arr.assign(n + 1, 0);
	cpp_int x = 1;
	arr.at(0) = 1;
	int j = 1;
	for (cpp_int i = 2; i <= n; ++i) {
		x *= i;
		arr[j++] = x;
	}
}
vector<double> arrlog;
void init(ll nx) {
	arrlog.assign(nx + 1, 0.0);
	for (int i = 1; i <= nx; ++i) {
		arrlog.at(i) = log10(1.*i);
		arrlog.at(i) += arrlog.at(i - 1);
	}
}
int findDigits(int n)
{
	// factorial exists only for n>=0 
	if (n < 0)
		return 0;

	// base case 
	if (n <= 1)
		return 1;

	// else iterate through n and calculate the 
	// value 
	double digits = 0;
	for (int i = 2; i <= n; i++)
		digits += log10(i);

	return floor(digits) + 1;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	ll nx = 0;
	vector<ll> a;
	while (q--) {
		int n;
		cin >> n;
		{
			int res = findDigits(n);
			cout << res << endl;
			continue;

		}
		a.push_back(n);
		if (n > nx)nx = n;
	}
	{
		return 0;
	}
	init(nx);
	for (const auto& x : a) {
		int res = static_cast<int>(std::floor(arrlog[x - 1])) + 1;
		cout << res << "\n";
	}
	return 0;
}