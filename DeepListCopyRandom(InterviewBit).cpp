/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
using List = RandomListNode;
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
	if (A == 0)return nullptr;
	std::unordered_map<List*, int> fun1;
	std::unordered_map<int, int> fun2;
	vector<List*> arr;
	int i = 0, n = 0;
	List * temp = A;
	List * h = 0, *current = 0;
	while (temp != 0) {
		fun1[temp] = i++;
		++n;
		if (h == 0) {
			h = new List(temp->label);
			current = h;
		}
		else {
			current->next = new List(temp->label);
			current = current->next;
		}
		arr.push_back(current);
		temp = temp->next;
	}
	temp = A, current = h;
	i = 0;
	while (temp != 0) {
		if (temp->random != NULL) {
			fun2[i] = fun1[temp->random];
			current->random = arr[fun2[i]];
		}
		temp = temp->next;
		current = current->next;
		++i;
	}
	return h;
}
