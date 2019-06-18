#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (q--) {
		string s("");
		std::getline(std::cin, s);
		char p;
		int csen = 0, cword = 0;
		int l = (int)s.size();
		int i = 0;
		while (i < l) {
			if (ispunct(s[i])) {
				if (!i || (i && !ispunct(s[i - 1])))++csen;
			}
			else if (isalpha(s[i])) {
				if (!i || (i && !isalpha(s[i - 1])))++cword;
			}
			++i;
		}
		if (s.size() > 0 && !ispunct(s.back()))++csen;
		cout << csen << " " << cword << "\n";
	}
	return 0;
}