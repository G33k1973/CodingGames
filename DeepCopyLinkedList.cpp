#define pb push_back
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)return NULL;
		std::unordered_map<Node*, int> dict;
		std::vector<Node*> ra;
		int i = 0;
		Node * curr{ head };
		while (curr != NULL) {
			dict.insert(make_pair(curr, i++));
			ra.pb(curr->random);
			curr = curr->next;
		}
		Node * h = NULL, *t = 0;
		curr = head;
		vector<Node*> arr;
		i = 0;
		int n = (int)ra.size();
		while (i < n) {
			int x = curr->val;
			if (h == 0) {
				h = new Node();
				h->val = x;
				h->next = h->random = NULL;
				t = h;
			}
			else {
				t->next = new Node();
				t->next->val = x;
				t->next->random = t->next->next = NULL;
				t = t->next;
			}
			arr.pb(t);
			curr = curr->next;
			++i;
		}
		t->next = NULL;
		i = 0;
		t = h;
		while (i < n) {
			Node * temp = ra[i];
			if (temp != NULL) {
				t->random = arr.at(dict[temp]);
			}
			++i;
			t = t->next;
		}
		return h;
	}
};