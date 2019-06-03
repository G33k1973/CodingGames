{

#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
	int  t, n, i, a[100001];
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> a[i];
		cout << findLongestConseqSubseq(a, n) << endl;
	}

	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

#define M 100005
int findLongestConseqSubseq(int arr[], int n)
{
	//Your code here
	int h[M] = { 0 };
	int i = 0;
	int mn = INT_MAX;
	int mx = INT_MIN;
	while (i < n) {
		int x = *(arr + i);
		assert(x >= 0 && x < M);
		++h[x];
		if (x < mn)mn = x;
		if (x > mx)mx = x;
		++i;
	}
	i = mn;
	int res = 1;
	while (i < mx) {
		if (h[i] == 0) {
			++i;
			continue;
		}
		int sub = 1;
		int j = i + 1;
		while (j <= mx && h[j] > 0) {
			++sub;
			++j;
		}
		res = max(res, sub);
		if (j == mx)break;
		i = j;
	}
	return res;
}