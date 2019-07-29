#include<bits/stdc++.h>


using namespace std;

int LDS(vector<int> a, int n)
{
	multiset<int> M;
	multiset<int>::iterator it;

	for (int i = 0; i < n; i++)
	{
		M.insert(a[i]);

		it = M.upper_bound(a[i]);

		if (it != M.end())
			M.erase(it);
	}
	return M.size();
}

int minChanges(int a[], int n)
{
	vector<int> c(n, 0);
	for (int i = 0; i < n; i++)
		c[i] = a[i] - i;

	return n - LDS(c, n);
}

int main()
{
	//code
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[1000001] = { 0 };
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << minChanges(a, n) << endl;
	}

	return 0;
}