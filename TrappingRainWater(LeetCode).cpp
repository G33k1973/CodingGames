class Solution {
private:
	vector<string> res;
	unordered_map<char, string> h{ {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
				{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz" } };
	void dfs(string& s, int l, int i, string& temp) {
		if (i == l) {
			res.push_back(temp);
			return;
		}
		for (int j = 0; j<int(h[s[i]].size()); ++j) {
			temp.push_back(h[s[i]][j]);
			dfs(s, l, i + 1, temp);
			temp.pop_back();
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		int l = int(digits.size());
		if (l == 0)return res;
		for (int i = 0; i<int(h[digits[0]].size()); ++i) {
			string temp(1, h[digits[0]][i]);
			dfs(digits, l, 1, temp);
		}
		return res;
	}
};

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == 0)return nullptr;
		unordered_map<Node*, int> h;
		Node * c = head;
		int i = 0;
		while (c != 0) {
			h.insert(make_pair(c, i));
			++i, c = c->next;
		}
		vector<int> fun(i, -1);
		c = head;
		i = 0;
		while (c != 0) {
			if (c->random != NULL) {
				fun[i] = h[c->random];
			}
			++i;
			c = c->next;
		}
		vector<Node*> temp;
		Node * head2 = 0;
		Node * c2 = 0;
		c = head;
		while (c != 0) {
			if (head2 == 0) {
				head2 = new Node(c->val);
				c2 = head2;
			}
			else {
				c2->next = new Node(c->val);
				c2 = c2->next;
			}
			temp.push_back(c2);
			c = c->next;
		}
		i = 0;
		while (i < int(temp.size())) {
			if (fun[i] != -1) {
				temp[i]->random = temp[fun[i]];
			}
			++i;
		}
		return head2;
	}
};

class Solution {
public:
	int trap(vector<int>& height) {
		int n = static_cast<int>(height.size());
		if (n < 3)return 0;
		{
			vector<int> arr(begin(height), end(height));
			// left[i] contains height of tallest bar to the 
	// left of i'th bar including itself 
			int left[n];

			// Right [i] contains height of tallest bar to 
			// the right of ith bar including itself 
			int right[n];

			// Initialize result 
			int water = 0;

			// Fill left array 
			left[0] = arr[0];
			for (int i = 1; i < n; i++)
				left[i] = max(left[i - 1], arr[i]);

			// Fill right array 
			right[n - 1] = arr[n - 1];
			for (int i = n - 2; i >= 0; i--)
				right[i] = max(right[i + 1], arr[i]);

			// Calculate the accumulated water element by element 
			// consider the amount of water on i'th bar, the 
			// amount of water accumulated on this particular 
			// bar will be equal to min(left[i], right[i]) - arr[i] . 
			for (int i = 0; i < n; i++)
				water += min(left[i], right[i]) - arr[i];
			return water;
		}
		stack<int> s;
		vector<int> ger(n, -1);
		int i = n - 1;
		while (i >= 0) {
			while (!s.empty() && height[i] > height[s.top()])s.pop();
			if (!s.empty())ger[i] = s.top();
			s.push(i);
			--i;
		}
		i = 0;
		int res = 0;
		while (i < n - 1) {
			if (ger[i] == -1) {
				++i;
				continue;
			}
			int j = ger[i];
			if (j == (i + 1)) {
				i = j;
				continue;
			}
			int k = i + 1;
			while (k < j) {
				//cout<<k<<endl;
				res += min(height[i], height[ger[i]]) - height[k++];
			}
			i = j;
		}
		reverse(begin(height), end(height));
		while (!s.empty())s.pop();
		i = n - 1;
		ger.assign(n, -1);
		while (i >= 0) {
			while (!s.empty() && height[i] > height[s.top()])s.pop();
			if (!s.empty())ger[i] = s.top();
			s.push(i);
			--i;
		}
		i = 0;
		int res2 = 0;
		while (i < n - 1) {
			if (ger[i] == -1) {
				++i;
				continue;
			}
			int j = ger[i];
			if (j == (i + 1)) {
				i = j;
				continue;
			}
			int k = i + 1;
			while (k < j) {
				//cout<<k<<endl;
				res2 += min(height[i], height[ger[i]]) - height[k++];
			}
			i = j;
		}
		return max(res, res2);
	}
};