class MaxStack {
private:
	stack<int> st;
	map<int, int, greater<int>> stmax;
	unordered_map<int, int> removed;
public:
	/** initialize your data structure here. */
	MaxStack() {
		while (!st.empty())st.pop();
		if (stmax.size())stmax.clear();
		if (removed.size())removed.clear();
	}

	void push(int x) {
		st.push(x);
		++stmax[x];
	}

	int pop() {
		while (1) {
			auto it = removed.find(st.top());
			if (it != end(removed)) {
				--it->second;
				if (it->second == 0)it = removed.erase(it);
				st.pop();
			}
			else
				break;
		}
		int x = st.top();
		st.pop();
		auto it2 = stmax.find(x);
		--it2->second;
		if (it2->second == 0) {
			it2 = stmax.erase(it2);
		}
		return x;
	}

	int top() {
		while (1) {
			auto it = removed.find(st.top());
			if (it != end(removed)) {
				--it->second;
				if (it->second == 0)it = removed.erase(it);
				st.pop();
			}
			else
				break;
		}
		return st.top();
	}

	int peekMax() {
		return begin(stmax)->first;
	}

	int popMax() {
		auto it = begin(stmax);
		int val = it->first;
		int freq = it->second;
		int ontop = st.top();
		if (val == ontop) {
			st.pop();
		}
		else {
			removed[val]++;
		}
		--it->second;
		if (it->second == 0)stmax.erase(begin(stmax));
		return val;
	}
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */