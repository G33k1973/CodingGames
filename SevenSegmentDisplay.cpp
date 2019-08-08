#include<bits/stdc++.h>
using namespace std;
int get_segment(char ch)
{
	if (ch == '0') return 6;
	if (ch == '1') return 2;
	if (ch == '2') return 5;
	if (ch == '3') return 5;
	if (ch == '4') return 4;
	if (ch == '5') return 5;
	if (ch == '6') return 6;
	if (ch == '7') return 3;
	if (ch == '8') return 7;
	if (ch == '9') return 5;
}
int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		int total_seg = 0;
		for (int i = 0; i < n; i++) total_seg += get_segment(str[i]);
		string ans = "";
		for (int i = 0; i < n; i++)
		{
			int first = (n - i - 1) * 2;
			int second = (n - i - 1) * 7;
			for (int j = 0; j <= 9; j++)
			{
				int x = get_segment(j + '0');
				if (total_seg - x<first || total_seg - x>second) continue;
				if (total_seg - x >= 0)
				{
					char ch = j + '0';
					string flag(1, ch);
					ans += flag;
					total_seg -= x;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}