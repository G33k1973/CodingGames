#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		float x;
		cin >> x;
		std::stringstream ss;
		ss << x;
		string s = ss.str();
		//cout<<s<<endl;
		auto pos = s.find('.');
		if (pos == string::npos) {
			cout << "1\n";
			continue;
		}
		s = s.substr(pos + 1);
		int l = (int)s.size();
		int j = l - 1;
		while (l > 0 && s.back() == '0') {
			s.pop_back();
			--l;
		}
		if (l == 0) {
			cout << "1\n";
			continue;
		}
		int mul = pow(10, l);
		int y = stoi(s);
		//cout<<mul<<" "<<y<<endl;
		if (mul%y == 0) {
			cout << (mul / y) << "\n";
		}
		else {
			int res = mul;
			int mulo = mul;
			while (mul > 1) {
				mul--;
				int tot = mul * y;
				if (tot%mulo == 0) {
					res = mul;
				}
			}
			cout << res << "\n";
		}
	}
	return 0;
}