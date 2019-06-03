#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		cin >> n;
		long long int a[n + 1], s[n + 1], i;
		for (i = 1; i <= n; i++)
			cin >> a[i];

		s[1] = a[1];
		s[2] = a[2];
		s[3] = a[3];
		s[4] = a[4];
		long long int minm2 = 100005;
		if (n <= 4)
		{
			for (i = 1; i <= n; i++)
			{
				if (a[i] < minm2)
					minm2 = a[i];
			}

			cout << minm2 << endl;
		}




		else
		{

			for (i = 5; i <= n; i++)
				s[i] = min(min(s[i - 1], min(s[i - 2], s[i - 3])), s[i - 4]) + a[i];

			int  minm = min(min(min(s[n], s[n - 1]), s[n - 2]), s[n - 3]);
			cout << minm << endl;
		}

	}
	return 0;
}


