#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		std::unordered_map<char, set<std::string>> directory;
		while (n-- > 0) {
			string s;
			cin >> s;
			//if(s.empty())continue;
			char x = s.front();
			directory[x].insert(s);
		}
		string query;
		cin >> query;
		int l = static_cast<int>(query.size());
		string temp("");
		std::unordered_map<char, set<std::string>>::const_iterator it;
		std::set<std::string>::iterator ptr;
		for (int i = 0; i < l; ++i) {
			char y = query.operator[](i);
			temp.pb(y);
			if (!i) {
				it = directory.find(y);
				if (it == end(directory)) {
					for (int j = 0; j < l; ++j) {
						cout << "0\n";
					}
					break;
				}
			}
			ptr = it->second.lower_bound(temp);
			if (ptr == end(it->second)) {
				while (i < l) {
					cout << "0\n";
					++i;
				}
				break;
			}
			auto ptr2 = ptr;
			int c = 0;
			while (ptr2 != end(it->second)) {
				auto pos = (*ptr2).find(temp, 0);
				if (pos == std::string::npos || pos > 0)break;
				++c;
				cout << *ptr2++ << " ";
			}
			if (c == 0) {
				while (i < l) {
					cout << "0\n";
					++i;
				}
				break;
			}
			cout << endl;
		}
	}
	return 0;
}