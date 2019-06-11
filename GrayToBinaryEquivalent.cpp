#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
char XorChar(char x, char y) {
	if (x == y)return '0';
	return '1';
}
char flip(char x) {
	if (x == '0')return '1';
	return '0';
}
string GetBinary(int x) {
	string s("");
	while (x) {
		s.pb((x % 2) + '0');
		x /= 2;
	}
	reverse(begin(s), end(s));
	return std::move(s);
}
string BinToGray(string s) {
	string result("");
	result += s.front();
	for (int i = 1; i < (int)s.size(); ++i) {
		result += XorChar(s[i - 1], s[i]);
	}
	return result;
}
string GrayToBin(string s) {
	string gray("");
	gray += s.front();
	for (int i = 1; i < (int)s.length(); ++i) {
		if (s[i] == '0')gray += gray[i - 1];
		else gray += flip(gray[i - 1]);
	}
	return gray;
}
int BinToDecimal(string s) {
	int res = 0;
	unsigned int j = 0;
	for (int i = (int)(s.size() - 1); i >= 0; --i) {
		int val = s[i] - '0';
		if (val)res += (1 << j);
		++j;
	}
	return res;
}
int main() {
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (x == 0) {
			cout << "0\n";
			continue;
		}
		string binary = GetBinary(x);
		string grat = GrayToBin(binary);
		int res = BinToDecimal(grat);
		cout << res << endl;
	}
	return 0;
}