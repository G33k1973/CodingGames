#include<bits/stdc++.h>
using namespace std;
#define pb push_back
class Solution {
protected:
	vector<string> r;
	string temp = "";
	unordered_set<string> seen;
	void dfs(string& s, int i, int l, int ctbr, int otbr, int no) {
		if (i == l) {
			//cout<<temp<<" "<<no<<" "<<ctbr<<" "<<otbr<<" "<<endl;
			if (no == 0 && ctbr == 0 && otbr == 0 && seen.count(temp) == 0) {
				r.pb(temp);
				seen.insert(temp);
			}
			return;
		}
		if (isalpha(s[i])) {
			temp.pb(s[i]);
			dfs(s, i + 1, l, ctbr, otbr, no);
			temp.pop_back();
		}
		else if (s[i] == '(') {
			if (otbr > 0) {
				dfs(s, i + 1, l, ctbr, otbr - 1, no);
			}
			temp.pb(s[i]);
			dfs(s, i + 1, l, ctbr, otbr, no + 1);
			temp.pop_back();
		}
		else if (s[i] == ')') {
			if (ctbr > 0) {
				dfs(s, i + 1, l, ctbr - 1, otbr, no);
			}
			if (no > 0) {
				temp.pb(s[i]);
				dfs(s, i + 1, l, ctbr, otbr, no - 1);
				temp.pop_back();
			}
		}
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		int l = int(s.size());
		if (l == 0) {
			r.pb(string(""));
			return r;
		}
		if (l == 1) {
			if (isalpha(s.front())) {
				r.pb(s);
				return r;
			}
			s = "";
			r.pb(s);
			return r;
		}
		int ctbr{ 0 };
		int otbr{ 0 };
		int no = 0;
		for (char& x : s) {
			if (isalpha(x))continue;
			if (x == ')') {
				if (no == 0)++ctbr;
				else --no;
			}
			else {
				++no;
			}
		}
		otbr = no;
		if (ctbr == 0 && otbr == 0) {
			r.pb(s);
			return r;
		}
		dfs(s, 0, l, ctbr, otbr, 0);
		if (r.empty())r.pb(string(""));
		return r;
	}
};

bool ParseString(const std::string& x) {
	for (const char& y : x) {
		if (!isalpha(y) && x != ')'&&x != '(')return false;
	}
	return true;
}

int main(int argc, char ** argv) {
	string s = "";
	do {
		cout << "Enter a string with only letters and " << ") and ( characters.\n";
		std::getline(std::cin, s);
	} while (ParseString(s) == false);
	class Solution obj;
	vector<string> res = obj.removeInvalidParentheses(s);
	cout << "All valid parenthesis combinations are the following:\n";
	for (const std::string& y : res) {
		cout << y << endl;
	}
	return 0;
}