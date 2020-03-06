/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * h = 0, *c;
void Reverse(ListNode * A) {
	if (A == 0)return;
	int x = A->val;
	Reverse(A->next);
	if (h == 0) {
		h = new ListNode(x);
		c = h;
	}
	else {
		c->next = new ListNode(x);
		c = c->next;
	}
}
ListNode* Solution::reverseList(ListNode* A) {
	if (A == 0) {
		return 0;
	}
	h = 0;
	c = 0;
	Reverse(A);
	return h;
}
