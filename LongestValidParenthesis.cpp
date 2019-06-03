#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int doSomething(string text) {
	int maxans = 0;
	stack<int> st;
	st.push(-1);
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == '(') {
			st.push(i);
		}
		else {
			st.pop();
			if (st.empty()) {
				st.push(i);
			}
			else {
				maxans = max(maxans, i - st.top());
			}
		}
	}
	return maxans;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		cout << doSomething(s) << endl;
	}
	return 0;
}