#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = unsigned long long int;
#include <stdio.h>
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
long long lcm(long long a, long long b)
{
	return (a*b) / gcd(a, b);
}
unsigned long long int recursion(unsigned long long int* a, unsigned long long int curr, unsigned long long int k, int n)
{
	unsigned long long int ans = 0, next;
	if (n > 0)
	{
		next = lcm((*a), curr);
		ans = ans + k / next;
		ans = ans + recursion(a + 1, curr, k, n - 1) - recursion(a + 1, next, k, n - 1);

	}
	return ans;
}
int main() {
	int T;
	scanf("%d", &T);
	int i, n, j;
	long long k;
	for (i = 0; i < T; i++)
	{
		scanf("%d", &n);
		unsigned long long int a[n];
		for (j = 0; j < n; j++)
		{
			scanf("%llu", a + j);
		}
		scanf("%lld", &k);
		printf("%llu", recursion(a, 1, k, n));
		if (i != T - 1)
		{
			printf("\n");
		}

	}
	return 0;
}