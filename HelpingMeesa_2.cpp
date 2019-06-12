#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		string fa = to_string(a);
		string fb = to_string(b);
		if (fa.size() < fb.size())cout << fb << endl;
		else if (fa.size() == fb.size()) {
			if (a < b)cout << fb << endl;
			else {
				fa = fb;
				fa.insert(0, 1, '1');
				cout << fa << endl;
			}
		}
		else if (fa.size() > fb.size()) {
			string c = fb;
			int difflen = static_cast<int>(fa.size()) - static_cast<int>(fb.size());
			string temp = fa.substr(0, difflen);
			int c4_7 = 0;
			for (auto& x : temp) {
				if (x == '4' || x == '7') {
					++c4_7;
					break;
				}
			}
			temp += c;
			if (temp > fa && c4_7 == 0) {
				cout << temp << endl;
				continue;
			}
			//cout<<temp<<endl;
			string sub = std::string(difflen, '0');
			int cfront = fa.front() - '0';
			if (cfront != 9) {
				if (cfront == 3 || cfront == 6)cfront += 2;
				else cfront += 1;
				sub.at(0) = cfront + '0';
			}
			else {
				sub.insert(0, 1, '1');
			}
			sub += c;
			cout << sub << endl;
		}
	}
	return 0;
}