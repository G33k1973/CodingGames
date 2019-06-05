#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool isoperator(const char& ch) {
	return (ch == '-' || ch == '+' || ch == '*' || ch == '/');
}
void dfs(const std::string& s, int l, int i, float a, string b, char op, float& ans) {
	if (i == l) {
		if (op == '@')ans = a;
		else {
			float y = stof(b);
			float x = a;
			if (op == '+') {
				ans = (x + y);
			}
			else if (op == '-') {
				ans = x - y;
			}
			else if (op == '*') {
				ans = x * y;
			}
			else if (op == '/') {
				ans = x / y;
			}
		}
		return;
	}
	if (isoperator(s[i])) {
		if (op != '@') {
			float y = std::stof(b);
			float x = a;
			float z = 0;
			//cout<<x<<" "<<y<<endl;
			if (op == '+') {
				z = (x + y);
			}
			else if (op == '-') {
				z = x - y;
			}
			else if (op == '*') {
				z = x * y;
			}
			else if (op == '/') {
				z = x / y;
			}
			b.clear();
			dfs(s, l, i + 1, z, b, s[i], ans);
		}
		else if (op == '@') {
			int val = std::stoi(b);
			//cout<<b<<endl;
			b.clear();
			dfs(s, l, i + 1, val, b, s[i], ans);
		}
	}
	else {
		b.push_back(s[i]);
		dfs(s, l, i + 1, a, b, op, ans);
	}
	return;
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int l = (int)s.size();
		string b("");
		int a = 0;
		float res = 0;
		dfs(s, l, 0, 0, b, '@', res);
		cout << static_cast<int>(std::floor(res)) << endl;
	}
}