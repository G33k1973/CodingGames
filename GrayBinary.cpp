#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair

char CXor(char a, char b) {
	return (a == b) ? ('0') : ('1');
}

char Flip(char a) {
	return (a == '0') ? ('1') : ('0');
}

string G2B(const std::string& s) {
	string t(1, s[0]);
	int i = 1, l = static_cast<int>(s.length());
	while (i < l) {
		if (s[i] == '0')t += t[i - 1];
		else t += Flip(t[i - 1]);
		++i;
	}
	return t;
}

string B2G(const std::string& s) {
	string t(1, s[0]);
	int i = 1;
	int l = (int)s.size();
	while (i < l) {
		t += CXor(s[i], s[i - 1]);
		++i;
	}
	return t;
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		string b, g;
		cin >> b >> g;
		cout << B2G(b) << '\n';
		cout << G2B(g) << '\n';
	}
}