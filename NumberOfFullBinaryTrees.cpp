#include<bits/stdc++.h>
using namespace std;
int total(int a[], int len)
{
	map<int, int> m;
	for (int i = 0; i < len; i++)
		m[a[i]] = 1;
	len = m.size();
	for (auto it = m.begin(); it != m.end(); it++)
	{
		for (auto it2 = it; it2 != m.end(); it2++)
		{
			if (it->first != 1 && it2->first != 1)
			{
				int root = it->first * it2->first;
				if (m.count(root) != 0 && it != it2)
					m[root] += 2 * it->second*it2->second;
				else if (m.count(root) != 0 && it == it2)
					m[root] += it->second * it2->second;
			}
		}
	}
	int sum = 0;
	for (auto x : m)
	{
		sum += x.second;
	}
	return sum;
}
int main()
{
	//code
	int testcases;
	cin >> testcases;
	vector<int> ans;
	for (int i = 0; i < testcases; i++)
	{
		int len;
		cin >> len;
		int a[len];
		for (int i = 0; i < len; i++)
			cin >> a[i];
		ans.push_back(total(a, len));
	}
	for (auto x : ans)
		cout << x << endl;
	return 0;
}