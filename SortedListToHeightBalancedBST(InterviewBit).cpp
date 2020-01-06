/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
#define pb push_back
TreeNode* build(vector<int>& a, int l, int h) {
	if (l > h)return NULL;
	int m = l + (h - l) / 2;
	TreeNode * temp = new TreeNode(a.operator[](m));
	if (l == h)return temp;
	temp->left = build(a, l, m - 1);
	temp->right = build(a, m + 1, h);
	return temp;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if (A == 0)return NULL;
	vector<int> arr;
	int n = -1;
	while (A) {
		arr.pb(A->val);
		A = A->next;
		++n;
	}
	int low = 0, high = n;
	return build(arr, low, high);
}
