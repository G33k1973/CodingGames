#define CHARS 255
class Solution {
public:
	string frequencySort(string s) {
		int l = int(s.size());
		if (l < 2)return s;
		int h[CHARS + 1] = { 0 };
		for (auto& x : s)++h[x];
		int h2[CHARS + 1] = { 0 };
		string t("");
		for (int i = 0; i < l; ++i) {
			if (h2[s[i]] == 0)t.push_back(s[i]);
			++h2[s[i]];
		}
		sort(begin(t), end(t), [&](const char& x, const char& y)->bool {return h[x] > h[y]; });
		int i = 0;
		int m = int(t.size());
		int j = 0;
		while (i < m) {
			char x = t[i];
			int freq = h[x];
			while (freq-- > 0) {
				s[j++] = x;
			}
			++i;
		}
		return s;
	}
};

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};
*/
#define pb push_back
class Solution {
protected:
	vector<int> arr;
	void dfs(Node * h) {
		if (h == 0)return;
		arr.pb(h->val);
		if (h->child) {
			dfs(h->child);
		}
		dfs(h->next);
	}
public:
	Node* flatten(Node* head) {
		if (head == 0)return NULL;
		dfs(head);
		Node * h = 0, *t = 0;
		for (auto& x : arr) {
			if (h == 0) {
				h = new Node();
				h->child = 0;
				h->val = x;
				h->next = 0;
				h->prev = 0;
				t = h;
			}
			else {
				t->next = new Node();
				t->next->child = 0;
				t->next->next = 0;
				t->next->val = x;
				t->next->prev = t;
				t = t->next;
			}
		}
		return h;
	}
};