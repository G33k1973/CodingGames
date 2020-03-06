/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef ListNode Node;
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		// If list is empty or has only one node 
	// without loop 
		unordered_set<ListNode*> h;
		ListNode * c = head;
		while (c) {
			if (h.count(c) > 0)return c;
			h.insert(c);
			c = c->next;
		}
		return 0;
		
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
class Solution {
private:
	vector<ListNode*> arr;
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == 0)return NULL;
		ListNode * current = head;
		while (current) {
			arr.pb(current);
			current = current->next;
		}
		int n = int(arr.size());
		if (n == 1)return head;
		int i = 0;
		while (i < n) {
			int j = i + 2;
			if (j >= n) {
				arr[i]->next = 0;
				break;
			}
			arr[i]->next = arr[j];
			arr[j]->next = 0;
			i = j;
		}
		int k = i;
		arr[k]->next = arr[1];
		i = 1;
		while (i < n) {
			int j = i + 2;
			if (j >= n) {
				arr[i]->next = 0;
				break;
			}
			arr[i]->next = arr[j];
			arr[j]->next = 0;
			i = j;
		}
		return head;
	}
};