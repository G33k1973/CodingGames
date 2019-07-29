#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		unordered_map<string, int> h;
		pair<int, string> best{ 0,"" };
		while (n-- > 0) {
			string s("");
			cin >> s;
			++h[s];
			if (h[s] >= best.first) {
				best = { h[s],s };
			}
		}
		cout << best.second << "\n";
	}
	return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		cin.ignore();
		std::string ars("");
		std::getline(std::cin, ars);
		ars += " ";
		int i = 0;
		string sub("");
		unordered_map<string, int> h;
		pair<int, string> best{ 0,"" };
		int c = 0;
		while (i < (int)ars.size()) {
			if (!isalpha(ars[i])) {
				if (!sub.empty()) {
					//cout<<sub<<endl;
					++h[sub];
					if (h[sub] >= best.first) {
						best = make_pair(h[sub], sub);
					}
					++c;
					if (c == n)break;
					sub.clear();
				}
			}
			else {
				sub += ars[i];
			}
			++i;
		}
		cout << best.second << "\n";
	}
	return 0;
}