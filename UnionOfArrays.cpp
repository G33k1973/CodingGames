/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/
//https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays/1
#include <cassert>
#define SIZE 1000001
int arr1[1000000];
int arr2[1000000];
void findUnion(int N, int M)
{
	//Your code here
	//n is size of arr1
	//m is isze of arr2
	bool visited[SIZE] = { false };
	int i = 0;
	while (i < N) {
		int x = arr1[i++];
		assert(x > 0 && x < SIZE);
		if (!visited[x]) {
			visited[x] = true;
			cout << x << " ";
		}
	}
	i = 0;
	while (i < M) {
		int x = arr2[i++];
		assert(x > 0 && x < SIZE);
		if (!visited[x]) {
			visited[x] = true;
			cout << x << " ";
		}
	}
	return;
}