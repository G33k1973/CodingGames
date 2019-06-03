/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
Node *zigZack(Node* head)
{
	// your code goes here
	if (head == nullptr)return head;
	vector<int> cum;
	while (head) {
		cum.pb(head->data);
		head = head->next;
	}
	int flag = 0;
	int n = static_cast<int>(cum.size());
	for (int i = 0; i <= n - 2; ++i) {
		if (!flag) {
			if (cum[i] > cum[i + 1]) {
				std::swap(cum[i], cum[i + 1]);
			}
		}
		else {
			if (cum[i] < cum[i + 1]) {
				std::swap(cum[i], cum[i + 1]);
			}
		}
		flag = !flag;
	}
	Node * h = NULL;
	Node * c = NULL;
	for (auto& x : cum) {
		if (h == NULL) {
			h = new Node;
			h->next = 0;
			h->data = x;
			c = h;
		}
		else {
			c->next = new Node;
			c->next->data = x;
			c->next->next = 0;
			c = c->next;
		}
	}
	return h;
}