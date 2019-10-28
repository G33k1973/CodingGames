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
protected:
	void MyReverse(int * start, int * end) {
		while (start < end) {
			int temp = *start;
			*start = *end;
			*end = temp;
			++start, --end;
		}
		return;
	}
	vector<int> as(vector<int> a, vector<int> b) {
		int n = (int)a.size();
		int m = (int)b.size();
		vector<int> c;
		MyReverse(a.data(), a.data() + n - 1);
		MyReverse(b.data(), b.data() + m - 1);
		int i = 0, j = 0, carry = 0;
		while (i < n&&j < m) {
			int res = a[i++] + b[j++] + carry;
			c.pb(res % 10);
			carry = res / 10;
		}
		while (i < n) {
			int res = a[i++] + carry;
			c.pb(res % 10);
			carry = res / 10;
		}
		while (j < m) {
			int res = b[j++] + carry;
			c.pb(res % 10);
			carry = res / 10;
		}
		while (carry) {
			c.pb(carry % 10);
			carry /= 10;
		}
		MyReverse(c.data(), c.data() + c.size() - 1);
		return c;
	}
	vector<int> ConvertFromList(ListNode * h) {
		vector<int> temp;
		while (h) {
			temp.pb((*h).val);
			h = h->next;
		}
		return temp;
	}
	ListNode * RetrieveLinkedList(const std::vector<int>& arr) {
		int n = int(arr.size());
		int i = 0;
		ListNode * head = NULL, *c = NULL;
		while (i < n) {
			int y = arr.operator[](i++);
			if (head == NULL) {
				head = new ListNode(y);
				c = head;
			}
			else {
				c->next = new ListNode(y);
				c = c->next;
			}
		}
		c->next = 0;
		return head;
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == 0 && l2 == 0)return NULL;
		if (l1 == 0)return l2;
		if (l2 == 0)return l1;
		return RetrieveLinkedList(as(ConvertFromList(l1), ConvertFromList(l2)));
	}
};