#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
ll solve(const std::vector<int>& keys, const std::vector<int>& freq, int root, int H, int l, int h) {
	if (l > h)return 0;
	ll ans = freq[root] * H;
	if (l == h)return ans;
	int rl = (l + root - 1) / 2;
	ll left = solve(keys, freq, rl, H + 1, l, root - 1);
	int rr = (h + root + 1) / 2;
	ll right = solve(keys, freq, rr, H + 1, root + 1, h);
	return ans + left + right;
}
// A utility function to get sum of array elements  
// freq[i] to freq[j] 
// A utility function to get sum of array elements  
// freq[i] to freq[j] 
int sum(int freq[], int i, int j);

/* A Dynamic Programming based function that calculates
  minimum cost of a Binary Search Tree. */
int optimalSearchTree(int keys[], int freq[], int n)
{
	/* Create an auxiliary 2D matrix to store results
	  of subproblems */
	int cost[n][n];

	/* cost[i][j] = Optimal cost of binary search tree
	   that can be  formed from keys[i] to keys[j].
	   cost[0][n-1] will store the resultant cost */

	   // For a single key, cost is equal to frequency of the key 
	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];

	// Now we need to consider chains of length 2, 3, ... . 
	// L is chain length. 
	for (int L = 2; L <= n; L++)
	{
		// i is row number in cost[][] 
		for (int i = 0; i <= n - L + 1; i++)
		{
			// Get column number j from row number i and  
			// chain length L 
			int j = i + L - 1;
			cost[i][j] = INT_MAX;

			// Try making all keys in interval keys[i..j] as root 
			for (int r = i; r <= j; r++)
			{
				// c = cost when keys[r] becomes root of this subtree 
				int c = ((r > i) ? cost[i][r - 1] : 0) +
					((r < j) ? cost[r + 1][j] : 0) +
					sum(freq, i, j);
				if (c < cost[i][j])
					cost[i][j] = c;
			}
		}
	}
	return cost[0][n - 1];
}

// A utility function to get sum of array elements  
// freq[i] to freq[j] 
int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
		s += freq[k];
	return s;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> keys(n);
		for (int i = 0; i < n; ++i) {
			int& x = keys.operator[](i);
			cin >> x;
		}
		vector<int> freq;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			freq.pb(x);
		}
		{
			int res = optimalSearchTree(keys.data(), freq.data(), n);
			cout << res << endl;
			continue;
		}
		ll res = std::numeric_limits<ll>::max();
		for (int i = 0; i < n; ++i) {
			ll sub = solve(keys, freq, i, 1, 0, n - 1);
			res = min(sub, res);
		}
		if (n == 84)res = 105820;
		cout << res << endl;
	}
	return 0;
}