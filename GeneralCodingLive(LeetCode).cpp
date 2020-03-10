/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr)return NULL;
		vector<ListNode*> arr;
		int n = 0;
		while (head) {
			++n;
			arr.push_back(head);
			head = head->next;
		}
		if (n & 1)return arr[n / 2];
		return arr[n / 2];
	}
};

class Solution {
private:
	vector<int> dp;
	bool dfs(vector<int>& nums, int n, int i) {
		if (i >= (n - 1))return true;
		if (dp[i] != -1)return bool(dp[i]);
		bool ans = false;
		if (nums[i] == 0)return false;
		for (int j = 1; j <= nums[i]; ++j) {
			ans = ans || dfs(nums, n, i + j);
		}
		return dp[i] = ans;
	}
public:
	bool canJump(vector<int>& nums) {
		int n = int(nums.size());
		if (n == 0)return false;
		if (nums[0] == 0)return n == 1;
		dp.assign(n, -1);
		return dfs(nums, n, 0);
	}
};

class Solution {
public:
	string countAndSay(int n) {
		if (n == 0)return "";
		if (n == 1)return "1";
		string s = "1";
		for (int i = 2; i <= n; ++i) {
			char x = s.front();
			int c = 1;
			int j = 1, m = int(s.size());
			string z = "";
			while (j < m) {
				if (s[j] == x) {
					++c;
				}
				else {
					z += to_string(c);
					z += string(1, x);
					c = 1;
					x = s[j];
				}
				++j;
			}
			z += to_string(c);
			z += string(1, x);
			s = z;
		}
		return s;
	}
};