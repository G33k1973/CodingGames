#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isvowel(char x) {
	if (isupper(x))x = tolower(x);
	return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y');
}
int main() {
	//code
	int q;
	cin >> q;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (q--) {
		string s("");
		std::getline(std::cin, s);
		int l = s.size();
		bool prevvowel = false;
		int res = 0;
		int i = 0;
		int nvow = 0;
		while (i < l) {
			char x = s[i];
			if (isvowel(x)) {
				if (!prevvowel) {
					if (nvow && ((i == (l - 1) && s[i] == 'e') || (i < l - 1 && s[i + 1] == ' '&&s[i] == 'e'))) {

					}
					else {
						++nvow;
						++res;
					}
				}
				prevvowel = true;
			}
			else {
				prevvowel = false;
			}
			if (isspace(x))nvow = 0;
			++i;
		}
		cout << res << endl;
	}
	return 0;
}