#include <bits/stdc++.h>
using namespace std;

// v contains all 0's initially
void prepare(string s, vector<int> &v) {
	bool flag = true;
	int flagG = 0;
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '+') {
			flag = flagG % 2 == 0;
		}
		else if (s[i] == '-') {
			flag = !(flagG % 2 == 0);
		}
		else if (s[i] == '(' && i - 1 >= 0) {
			if (s[i - 1] == '-') flagG += 1;
		}
		else if (s[i] == ')') {
			if (flagG > 0) flagG--;
		}
		else {
			if (flag) v[s[i] - 'a'] += 1;
			else v[s[i] - 'a'] -= 1;
		}
		i++;
	}
};

bool check(string s, vector<int> &v) {
	bool flag = true;
	int flagG = 0;
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '+') {
			flag = flagG % 2 == 0;
		}
		else if (s[i] == '-') {
			flag = !(flagG % 2 == 0);
		}
		else if (s[i] == '(' && i - 1 >= 0) {
			if (s[i - 1] == '-') flagG += 1;
		}
		else if (s[i] == ')') {
			if (flagG > 0) flagG--;
		}
		else {
			if (flag) v[s[i] - 'a'] -= 1;
			else v[s[i] - 'a'] += 1;
		}
		i++;
	}
	for (int i = 0; i < 27; i++) {
		if (v[i] != 0) return false;
	}
	return true;
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		vector<int> v;
		for (int i = 0; i < 27; i++) v.push_back(0);
		prepare(a, v);
		if (check(b, v)) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}