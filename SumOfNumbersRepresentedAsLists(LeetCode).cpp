/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	ListNode * reverse(ListNode * l) {
		ListNode * current = l, *next = 0, *prev = 0;
		while (current != 0) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		l = prev;
		return l;
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == 0)return l2;
		if (l2 == 0)return l1;
		l1 = reverse(l1);
		l2 = reverse(l2);
		int carry = 0;
		ListNode * head = 0, *current = 0;
		while (l1 != 0 && l2 != 0) {
			int res = l1->val + l2->val + carry;
			if (head == 0) {
				head = new ListNode(res % 10);
				current = head;
			}
			else {
				current->next = new ListNode(res % 10);
				current = current->next;
			}
			carry = res / 10;
			l1 = l1->next, l2 = l2->next;
		}
		while (l1 != 0) {
			int res = l1->val + carry;
			if (head == 0) {
				head = new ListNode(res % 10);
				current = head;
			}
			else {
				current->next = new ListNode(res % 10);
				current = current->next;
			}
			carry = res / 10;
			l1 = l1->next;
		}
		while (l2 != 0) {
			int res = l2->val + carry;
			if (head == 0) {
				head = new ListNode(res % 10);
				current = head;
			}
			else {
				current->next = new ListNode(res % 10);
				current = current->next;
			}
			carry = res / 10;
			l2 = l2->next;
		}
		while (carry) {
			current->next = new ListNode(carry % 10);
			carry /= 10;
			current = current->next;
		}
		return reverse(head);
	}
};