#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void construct(string s, int low, int high, int n)
{
	if (low > high)
		return;
	for (int i = 0; i < n; i++)
	{
		if (i == low || i == high)
			cout << s[i];
		else cout << " ";
	}
	// cout<<endl;
	construct(s, low + 1, high - 1, n);
	if (low == high)
		return;
	else if (low < high)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == low || i == high)
				cout << s[i];
			else cout << " ";
		}
		//cout<<endl;
	}
}
int main()
{
	//code
	int t, n;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;

		n = s.length();
		construct(s, 0, n - 1, n);
		cout << endl;

	}
	return 0;
}