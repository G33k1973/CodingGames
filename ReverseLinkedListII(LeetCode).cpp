/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == 0)return head;
		ListNode * current = head, *prev = 0, *next = 0, *origin = 0, *first = 0;
		int c = 1;
		while (current != NULL) {
			if (c == m) {
				origin = current;
				next = current->next;
				current->next = prev;
				prev = current;
				if (c == n) {
					if (m == 1)head = current;
					else first->next = current;
					origin->next = next;
				}
				current = next;
			}
			else if (c > m&&c <= n) {
				next = current->next;
				current->next = prev;
				prev = current;
				if (c == n) {
					if (m == 1)head = current;
					else first->next = current;
					origin->next = next;
				}
				current = next;
			}
			else if (c < m) {
				first = current;
				current = current->next;
			}
			else if (c > n)break;
			++c;
		}
		return head;
	}
};