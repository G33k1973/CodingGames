#include <bits/stdc++.h>
#include <iostream>
using namespace std;

double GetArea(int a, int b, int c) {
	if (a >= (b + c) || b >= (a + c) || c >= (a + b))return 0.0;
	double p = .5*(a + b + c);
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		double area = GetArea(a, b, c);
		cout << std::fixed << std::setprecision(6) << area << "\n";
	}
}