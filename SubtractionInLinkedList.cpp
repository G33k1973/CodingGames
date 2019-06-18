#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
bool IsSmaller(const std::string& x, const std::string& y) {
	int n1 = static_cast<int>(x.length());
	int n2 = static_cast<int>(y.length());
	if (n1 > n2)return false;
	if (n1 < n2)return true;
	return (x.compare(y) < 0);
}
void MyReverse(string& s) {
	int n = int(s.length());
	int l = 0, h = n - 1;
	while (l < h) {
		char x = s.at(l);
		char y = s.at(h);
		s.at(l) = y;
		s.at(h) = x;
		++l, --h;
	}
	return;
}
string subtract(string& x, string& y) {
	if (IsSmaller(x, y))std::swap(x, y);
	int n1 = int(x.size());
	int n2 = int(y.size());
	int i = 0, carry = 0;
	string z("");
	MyReverse(x);
	MyReverse(y);
	while (i < n2) {
		int fx = x.at(i) - '0';
		int fy = y.at(i) - '0';
		int res = fx - fy - carry;
		if (res < 0) {
			z.pb((res + 10) + '0');
			carry = 1;
		}
		else {
			z.pb(res + '0');
			carry = 0;
		}
		++i;
	}
	while (i < n1) {
		int fx = x.at(i) - '0';
		int res = fx - carry;
		if (res < 0) {
			z.pb((res + 10) + '0');
			carry = 1;
		}
		else {
			z.pb(res + '0');
			carry = 0;
		}
		++i;
	}
	MyReverse(z);
	return z;
}

/*You are required to complete this method*/
Node* subLinkedList(Node* l1, Node* l2)
{
	//Your code here
	if (l1 == 0 && l2 == 0)return NULL;
	if (l1 == 0)return l2;
	if (l2 == 0)return l1;
	string x(""), y("");
	while (l1) {
		x.pb(l1->data + '0');
		l1 = l1->next;
	}
	while (l2) {
		y.pb(l2->data + '0');
		l2 = l2->next;
	}
	string z = subtract(x, y);
	int left = std::max((int)x.size(), (int)y.size()) - int(z.size());
	if (left)z.insert(0, left, '0');
	Node * h = 0;
	Node * c = 0;
	for (int i = 0; i < (int)z.size(); ++i) {
		int val = z.operator[](i) - '0';
		if (h == NULL) {
			h = new Node;
			h->data = val;
			h->next = NULL;
			c = h;
		}
		else {
			c->next = new Node;
			c->next->data = val;
			c = c->next;
		}
	}
	c->next = NULL;
	return h;
}