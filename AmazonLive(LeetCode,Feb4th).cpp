class MinStack {
private:
	std::multiset<int> bst;
	std::stack<int> ms;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		ms.push(x);
		bst.insert(x);
	}

	void pop() {
		int y = ms.top();
		ms.pop();
		bst.erase(bst.find(y));
	}

	int top() {
		return ms.top();
	}

	int getMin() {
		return *(begin(bst));
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#define pb push_back
#define mp make_pair
class Solution {
private:
	vector<vector<string>> result;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int l = int(strs.size());
		if (l == 0)return result;
		if (l == 1) {
			result.pb(strs);
			return result;
		}
		unordered_map<string, vector<string>> h;
		for (auto& y : strs) {
			string temp(y);
			sort(begin(temp), end(temp));
			h[temp].pb(y);
		}
		for (auto& y : h)result.pb(y.second);
		return result;
	}
};