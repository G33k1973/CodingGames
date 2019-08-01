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
	string as(string x, string y) {
		int n = (int)x.length();
		int m = (int)y.length();
		if (n == 0) {
			return y;
		}
		if (m == 0) {
			return x;
		}
		string z("");
		int i(0), j(0), c(0);
		while (i < n&&j < m) {
			int fx = x[i++] - '0';
			int fy = y[j++] - '0';
			int res(fx + fy + c);
			z.pb((res % 10) + '0');
			c = res / 10;
		}
		while (i < n) {
			int fx(x[i++] - '0');
			int res = fx + c;
			z.pb((res % 10) + '0');
			c = res / 10;
		}
		while (j < m) {
			int fy = y[j++] - '0';
			int res = fy + c;
			z.pb((res % 10) + '0');
			c = res / 10;
		}
		while (c) {
			z.pb((c % 10) + '0');
			c /= 10;
		}
		return z;
	}
	ListNode * Accumulate_(string x, string y) {
		string z = (*this).as(x, y);
		ListNode * h = 0;
		ListNode * c = 0;
		for (const auto& x : z) {
			int val = x - '0';
			if (h == 0) {
				h = new ListNode(val);
				c = h;
			}
			else {
				c->next = new ListNode(val);
				c = c->next;
			}
		}
		return h;
	}
	string Extract(ListNode * t) {
		string s("");
		while (t != 0) {
			s.pb(t->val + '0');
			t = t->next;
		}
		return s;
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return this->Accumulate_(this->Extract(l1), this->Extract(l2));
	}
};