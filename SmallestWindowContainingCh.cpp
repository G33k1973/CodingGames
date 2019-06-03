{

#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		string pat;
		cin >> pat;

		solve(s, pat);

	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


void solve(string t, string p) {
	// Your code here
	int n = (int)t.length();
	int m = (int)p.length();
	if (m > n) {
		cout << "-1\n";
		return;
	}
	if (m == n) {
		string temp = t;
		sort(begin(t), end(t));
		sort(begin(p), end(p));
		if (t.compare(p) == 0)cout << temp;
		else cout << "-1";
		cout << "\n";
		return;
	}
	int start = 0;
	pair<int, pair<int, int>> ans{ n,{0,n - 1} };
	bool fnd = false;
	int hp[26] = { 0 };
	int ht[26] = { 0 };
	for (const auto& x : p)++hp[x - 'a'];
	int i = 0;
	int tot = 0;
	while (i < n) {
		char x = t.operator[](i);
		if (hp[x - 'a'] > 0) {
			if (ht[x - 'a'] < hp[x - 'a'])++tot;
			++ht[x - 'a'];
			while (tot == m) {
				if (fnd == false)fnd = true;
				int sub = i - start + 1;
				if (sub < ans.first) {
					ans = std::make_pair(sub, std::make_pair(start, i));
				}
				char y = t[start];
				if (hp[y - 'a'] == 0) {
					++start;
				}
				else {
					--ht[y - 'a'];
					if (ht[y - 'a'] < hp[y - 'a'])--tot;
					++start;
				}
			}
		}
		++i;
	}
	if (fnd ^ 1)cout << "-1\n";
	else {
		string res = t.substr(ans.second.first, ans.first);
		res += "\n";
		cout << res;
	}
}