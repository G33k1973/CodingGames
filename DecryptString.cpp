#include <bits/stdc++.h>
#include<sstream>
using namespace std;
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int isstring(string x) {
	int n = x.length();
	for (int i = 0; i < n; i++) {
		if (!isalpha(x[i]))
			return 0;
	}
	return 1;
}
int isnumber(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (!isdigit(s[i]))
			return 0;
	}
	return 1;
}
int main() {
	//code
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		stack<string>st;
		st.push("/");
		for (int i = 0; i < s.size(); i++)
		{
			string t(1, s[i]);
			string x = "" + t;
			//cout<<x<<endl;
			if (isOperand(s[i]))
				st.push(x);
			if (isdigit(s[i]))
				st.push(x);
			if (s[i] == '[')
				st.push(x);
			if (s[i] == ']') {
				string temp = "";
				while (isstring(st.top())) {
					temp = st.top() + temp;
					// cout<<st.top();
					st.pop();
				}
				//cout<<st.top()<<endl;
				if (st.top() == "[")
					st.pop();
				string f = "";
				while (isnumber(st.top())) {
					f = st.top() + f;
					st.pop();
				}
				//cout<<f<<endl;
				stringstream ss;
				ss << f;
				int x;
				ss >> x;

				string y = temp;
				for (int i = 1; i < x; i++)
					temp = y + temp;
				//st.pop();
				st.push(temp);
			}
			//cout<<st.top();
		}
		cout << st.top() << endl;
	}
	return 0;
}