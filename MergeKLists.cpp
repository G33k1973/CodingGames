/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define pb push_back
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	if (n == 1)return A.front();
	std::map<int, vector<ListNode*>, less<int>> h;
	for (auto& x : A) {
		ListNode * current = x;
		while (current) {
			h[current->val].pb(current);
			current = current->next;
		}
	}
	std::map<int, vector<ListNode*>, less<int>>::const_iterator ptr = begin(h);
	ListNode * head = 0, *temp = 0;
	while (ptr != end(h)) {
		int y = ptr->first;
		for (auto& x : ptr->second) {
			if (head == 0) {
				head = x;
				temp = head;
			}
			else {
				temp->next = x;
				temp = temp->next;
			}
		}
		++ptr;
	}
	temp->next = 0;
	return head;
}
