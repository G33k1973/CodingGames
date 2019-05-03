#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
vector<ll> elements;
#define pb push_back
void maxProduct(ll arr[], int n)
{
	// An array ti store  closest smaller element on left 
	// side of every element. If there is no such element 
	// on left side, then smaller[i] be -1. 
	ll smaller[n];
	smaller[0] = -1;// no smaller element on right side 

	// create an empty set to store visited elements from 
	// left side. Set can also quickly find largest smaller 
	// of an element. 
	set<ll>S;
	for (int i = 0; i < n; i++)
	{
		// insert arr[i] into the set S 
		auto j = S.insert(arr[i]);
		auto itc = j.first; // points to current element in set 

		--itc; // point to prev element in S 

		// If current element has previous element 
		// then its first previous element is closest 
		// smaller element (Note : set keeps elements 
		// in sorted order) 
		if (itc != S.end())
			smaller[i] = *itc;
		else
			smaller[i] = -1;
	}


	// Initialize greatest on right side. 
	ll max_right = arr[n - 1];
	ll result = -1;
	// This loop finds greatest element on right side 
	// for every element. It also updates result when 
	// required. 
	for (int i = n - 2; i >= 1; i--)
	{
		// If current element is greater than all 
		// elements on right side, update max_right 
		if (arr[i] > max_right)
			max_right = arr[i];

		// If there is a greater element on right side 
		// and there is a smaller on left side, update 
		// result. 
		else if (smaller[i] != -1) {
			if (smaller[i] != arr[i] && arr[i] != max_right) {
				ll parprod = smaller[i] * arr[i] * max_right;
				if (parprod > result) {
					result = parprod;
					elements = vector<ll>{ smaller[i],arr[i],max_right };
				}
			}
		}
	}

	return;
}
void dfs(vector<ll>&a, int n, int i, int j, ll& ans, ll prod, int p, vector<ll>& b) {
	if (p == 0) {
		if (prod > ans) {
			ans = prod;
			elements = b;
		}
		return;
	}
	if (i == n)return;
	for (int k = i; k < n; ++k) {
		if (a[k] > a[j]) {
			if (p == 3) {
				b.pb(a[j]);
				b.pb(a[k]);
				dfs(a, n, k + 1, k, ans, a[j] * a[k], p - 2, b);
				b.pop_back();
				b.pop_back();
			}
			else if (p == 1) {
				b.pb(a[k]);
				dfs(a, n, k + 1, k, ans, prod*a[k], p - 1, b);
				b.pop_back();
			}
		}
	}
	return;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		if (!elements.empty())elements.clear();
		int n;
		sc = scanf("%d", &n);
		vector<ll> a(n);
		map<ll, vector<int>> h;
		int i = 0;
		for (auto& x : a) {
			sc = scanf("%lld", &x);
		}
		{
			maxProduct(a.data(), n);

		}
		if (elements.empty()) {
			printf("Not Present\n");
			continue;
		}
		for (const auto& x : elements)printf("%lld ", x);
		printf("\n");
		//printf("%lld\n",res);
	}
	return 0;
}