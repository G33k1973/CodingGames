#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back

string as(string x, string y) {
	string z("");
	reverse(begin(x), end(x));
	reverse(begin(y), end(y));
	int n = (int)x.size();
	int m = (int)y.size();
	int i, j, c = 0;
	i = j = 0;
	while (i < n&&j < m) {
		int fx = x[i] - '0';
		int fy = y[j] - '0';
		int res = fx + fy + c;
		z.pb((res % 10) + '0');
		c = res / 10;
		++i, ++j;
	}
	while (i < n) {
		int fx = x[i] - '0';
		int fy = 0;// y[j] - '0';
		int res = fx + fy + c;
		z.pb((res % 10) + '0');
		c = res / 10;
		++i;
	}
	while (j < m) {
		int fx = 0;// x[i] - '0';
		int fy = y[j] - '0';
		int res = fx + fy + c;
		z.pb((res % 10) + '0');
		c = res / 10;
		++j;
	}
	while (c) {
		z.pb(c % 10 + '0');
		c /= 10;
	}
	reverse(begin(z), end(z));
	return z;
}

bool issumstring(const std::string& s, int l, int i, string x, string y = "") {
	if (i == l)return true;
	bool ans = false;
	if (y == "") {
		for (int j = i; j <= (2 * l) / 3; ++j) {
			y.pb(s[j]);
			string z = as(x, y);
			//cout<<x<<" "<<y<<" "<<z<<endl;
			auto pos = s.find(z, j + 1);
			if (pos != std::string::npos && pos == (j + 1)) {
				ans = ans || issumstring(s, l, j + 1 + (int)z.size(), y, z);
			}
		}
	}
	else {
		string z = as(x, y);
		auto pos = s.find(z, i);
		//cout<<x<<" "<<y<<" "<<z<<" "<<pos<<" "<<i<<endl;
		if (pos != std::string::npos && pos == (i)) {
			ans = ans || issumstring(s, l, i + (int)z.size(), y, z);
		}
	}
	return ans;
}
int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int l = (int)s.size();
		string t("");
		bool ans = false;
		for (int i = 0; i <= l / 3; ++i) {
			t.pb(s[i]);
			ans = issumstring(s, l, i + 1, t);
			if (ans == true)break;
		}
		cout << ans << "\n";
	}
}