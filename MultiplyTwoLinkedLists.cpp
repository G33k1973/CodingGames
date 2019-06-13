/*This is a function problem.You only need to complete the function given below*/
/* Linked list node structure
struct Node
{
	int data;
	Node* next;
};*/
/*The method multiplies
two  linked lists l1 and l2
and returns their product*/
/*You are required to complete this method*/
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
#define M 1000000007
#define pb push_back
long long  multiplyTwoLists(Node* l1, Node* l2)
{
	//Your code here
	string s1(""), s2("");
	if (l1 == 0 || l2 == 0)return 0;
	while (l1) {
		s1.pb(l1->data + '0');
		l1 = l1->next;
	}
	reverse(begin(s1), end(s1));
	while (l2) {
		s2.pb(l2->data + '0');
		l2 = l2->next;
	}
	reverse(begin(s2), end(s2));
	cpp_int mul = 1;
	cpp_int x = 0, y = 0;
	int L1 = (int)s1.size();
	int L2 = (int)s2.size();
	int i = 0;
	while (i < L1) {
		cpp_int val = s1[i] - '0';
		x += val * mul;
		mul *= 10;
		++i;
	}
	i = 0;
	mul = 1;
	while (i < L2) {
		cpp_int val = s2[i] - '0';
		y += val * mul;
		mul *= 10;
		++i;
	}
	cpp_int res = (x*y) % M;
	return static_cast<long long int>(res);
}