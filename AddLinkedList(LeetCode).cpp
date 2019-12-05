/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)return l2;
		if (l2 == NULL)return l1;
		ListNode * h = nullptr;
		ListNode * t = nullptr;
		int c = 0;
		while (l1 != 0 && l2 != 0) {
			int num = l1->val + l2->val + c;
			if (h == 0) {
				h = new ListNode(num % 10);
				t = h;
			}
			else {
				t->next = new ListNode(num % 10);
				t = t->next;
			}
			c = num / 10;
			l1 = l1->next, l2 = l2->next;
		}
		while (l1 != 0) {
			int num = l1->val + c;
			t->next = new ListNode(num % 10);
			c = num / 10;
			t = t->next, l1 = l1->next;
		}
		while (l2 != 0) {
			int num = l2->val + c;
			t->next = new ListNode(num % 10);
			c = num / 10;
			t = t->next, l2 = l2->next;
		}
		while (c > 0) {
			t->next = new ListNode(c % 10);
			t = t->next;
			c /= 10;
		}
		return h;
	}
};