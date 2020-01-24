/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A) {
	if (A == 0)return 0;
	vector<int> arr;
	while (A != 0) {
		arr.push_back(A->val);
		A = A->next;
	}
	int n = int(arr.size());
	if (n == 1)return 1;
	vector<vector<bool>> dp(n, vector<bool>(n, 0));
	int i, j, cl, res = 0;
	for (cl = 1; cl <= n; ++cl) {
		for (i = 0; i <= (n - cl); ++i) {
			j = i + cl - 1;
			if (cl == 1)dp[i][j] = true, res = 1;
			else if (cl == 2) {
				if (arr[i] == arr[j])dp[i][j] = true, res = 2;
				else dp[i][j] = false;
			}
			else {
				dp[i][j] = (arr[i] == arr[j] && dp[i + 1][j - 1]);
				if (dp[i][j])res = max(res, cl);
			}
		}
	}
	return res;
}
