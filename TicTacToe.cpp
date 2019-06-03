#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string s1("Valid\n");
string s2("Invalid\n");
std::unordered_map<char, int> hs{ {'X',1},{'O',2} };
int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	std::cin.ignore();
	while (q--) {
		int g[3][3] = { 0 };
		int i, j;
		string s("");
		std::getline(std::cin, s);
		/*
		cout<<s<<endl;
		{
			cout<<s1;
			continue;
		}
		*/
		i = 0;
		int c1 = 0, c2 = 0;
		for (auto& x : s) {
			char c = x;
			if (!(i & 1)) {
				if (!isspace(c)) {
					i /= 2;
					assert(c == 'O' || c == 'X');
					int I = i / 3, J = i % 3;
					g[I][J] = hs[c];
					if (g[I][J] == 1)++c1;
					else if (g[I][J] == 2)++c2;
					i *= 2;
				}
			}
			++i;
		}
		if (abs(c1 - c2) > 1) {
			cout << s2;
			continue;
		}
		int nw1 = 0, nw2 = 0;
		for (i = 0; i < 3; ++i) {
			int t1 = 0, t2 = 0;
			for (j = 0; j < 3; ++j) {
				if (g[i][j] == 1)++t1;
				else if (g[i][j] == 2)++t2;
			}
			if (t1 == 3)++nw1;
			if (t2 == 3)++nw2;
		}
		if ((nw1&&nw2) || nw1 > 2 || nw2 > 2) {
			cout << s2;
			continue;
		}
		for (j = 0; j < 3; ++j) {
			int t1 = 0, t2 = 0;
			for (i = 0; i < 3; ++i) {
				if (g[i][j] == 1)++t1;
				if (g[i][j] == 2)++t2;
			}
			if (t1 == 3)++nw1;
			if (t2 == 3)++nw2;
		}
		if ((nw1&&nw2) || nw1 > 2 || nw2 > 2) {
			cout << s2;
			continue;
		}
		i = 0, j = 0;
		int t1 = 0, t2 = 0;
		while (i < 3) {
			if (g[i][j] == 1)++t1;
			if (g[i][j] == 2)++t2;
			++i, ++j;
		}
		if (t1 == 3)++nw1;
		if (t2 == 3)++nw2;
		if ((nw1&&nw2) || nw1 > 2 || nw2 > 2) {
			cout << s2;
			continue;
		}
		t1 = t2 = 0;
		i = 2, j = 0;
		while (j < 3) {
			if (g[i][j] == 1)++t1;
			if (g[i][j] == 2)++t2;
			--i, ++j;
		}
		if (t1 == 3)++nw1;
		if (t2 == 3)++nw2;
		//cout<<nw1<<" "<<nw2<<" "<<c1<<" "<<c2<<endl;
		if ((nw1&&nw2) || nw1 > 2 || nw2 > 2) {
			cout << s2;
			continue;
		}
		if (nw1 == 0 && nw2 == 0 && c1 < c2) {
			cout << s2;
			continue;
		}
		if (nw2 >= 1 && c1 != c2) {
			cout << s2;
			continue;
		}
		if (nw1 >= 1 && c1 <= c2) {
			cout << s2;
			continue;
		}
		cout << s1;
	}
	return 0;
}