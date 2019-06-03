#include<stdio.h>
#include<string.h>
//https://practice.geeksforgeeks.org/problems/find-the-n-th-character/0/?ref=self
int someFunction(char* str, int R, int N)
{
	int i, half;
	int each_leaves = 1 << R;
	int sum = 0, len = strlen(str);
	int digit = 0;
	N++;// to make it 1 based indexing
	for (i = 0; i < len; ++i) {
		sum += each_leaves;
		if (sum >= N) {
			digit = str[i] == '0' ? 0 : 1;
			break;
		}
	}

	N -= (sum - each_leaves);

	for (i = 1; i <= R; ++i) {
		each_leaves /= 2;
		if (N > each_leaves) {
			if (digit == 0) digit = 1;
			else digit = 0;
			N -= each_leaves;
		}
	}


	return digit;
}


void input()
{
	int i, n, t, r;
	char arr[5005];
	scanf("%d", &t);

	while (t--)
	{
		scanf("%s", arr);
		scanf("%d %d", &r, &n);
		printf("%d\n", someFunction(arr, r, n));
	}


}


int main()
{
	input();
	return 0;
}