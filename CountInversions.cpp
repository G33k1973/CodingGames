#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
ll _mergeSort(ll arr[], ll temp[], int left, int right);
ll Merge(ll arr[], ll temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
number of inversions in the array */
ll mergeSort(ll arr[], int array_size)
{
	ll temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
ll _mergeSort(ll arr[], ll temp[], int left, int right)
{
	int mid;
	ll inv_count = 0;
	if (right > left)
	{
		/* Divide the array into two parts and
		call _mergeSortAndCountInv()
		for each of the parts */
		mid = (right + left) / 2;

		/* Inversion count will be sum of
		inversions in left-part, right-part
		and number of inversions in merging */
		inv_count = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		/*Merge the two parts*/
		inv_count += Merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
ll Merge(ll arr[], ll temp[], int left,
	int mid, int right)
{
	int i, j, k;
	ll inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];

			/* this is tricky -- see above
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
(if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		ll a[n];
		for (int i = 0; i < n; ++i)sc = scanf("%llu", &a[i]);
		ll res = mergeSort(a, n);
		printf("%llu\n", res);
	}
	return 0;
}