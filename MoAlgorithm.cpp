#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
// Variable to represent block size. This is made global 
// so compare() of sort can use it. 
int block;

// Structure to represent a query range 
struct Query
{
	int L, R, i, res;
};

// Function used to sort all queries so that all queries  
// of the same block are arranged together and within a block, 
// queries are sorted in increasing order of R values. 
bool compare(Query x, Query y)
{
	// Different blocks, sort by block. 
	if (x.L / block != y.L / block)
		return x.L / block < y.L / block;

	// Same block, sort by R value 
	return x.R < y.R;
}

bool compare2(Query x, Query y) {
	return x.i < y.i;
}
#define N 1001
// Prints sum of all query ranges. m is number of queries 
// n is size of array a[]. 
void queryResults(vector<int>& a, int n, vector<Query>& q, int m, int k)
{
	// Find block size 
	block = (int)sqrt(n);

	// Sort all queries so that queries of same blocks 
	// are arranged together. 
	sort(begin(q), end(q), compare);

	// Initialize current L, current R and current sum 
	int currL = 0, currR = 0;
	int currSum = 0;
	int freq[N] = { 0 };
	int sub = 0;
	// Traverse through all queries 
	for (int i = 0; i < m; i++)
	{
		// L and R values of current range 
		int L = q[i].L, R = q[i].R;

		// Remove extra elements of previous range. For 
		// example if previous range is [0, 3] and current 
		// range is [2, 5], then a[0] and a[1] are subtracted 
		while (currL < L)
		{
			--freq[a[currL]];
			currL++;
		}

		// Add Elements of current Range 
		while (currL > L)
		{
			++freq[a[currL - 1]];
			currL--;
		}
		while (currR <= R)
		{
			++freq[a[currR]];
			currR++;
		}

		// Remove elements of previous range.  For example 
		// when previous range is [0, 10] and current range 
		// is [3, 8], then a[9] and a[10] are subtracted 
		while (currR > R + 1)
		{
			--freq[a[currR - 1]];
			currR--;
		}
		sub = 0;
		for (int j = 1; j < N; ++j) {
			if (freq[j] >= k)++sub;
		}
		q[i].res = sub;
	}
	sort(begin(q), end(q), compare2);
	for (auto& x : q) {
		cout << x.res << " ";
	}
	cout << endl;
	return;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, m, k;
		cin >> n >> m >> k;
		std::vector<Query> qy;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> arr.at(i);
			assert(arr[i] > 0 && arr[i] < N);
		}
		for (int i = 0; i < m; ++i) {
			int l, r;
			cin >> l >> r;
			qy.pb({ l - 1,r - 1,i,0 });
		}
		queryResults(arr, n, qy, m, k);
	}
}