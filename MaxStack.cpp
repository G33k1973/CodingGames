class MaxStack {
protected:
	std::multiset<int, greater<int>> ms;
	std::stack<int> s;
public:
	/** initialize your data structure here. */
	MaxStack() {

	}

	void push(int x) {
		s.push(x);
		ms.insert(x);
	}

	int pop() {
		int val = s.top();
		s.pop();
		auto it = ms.find(val);
		it = ms.erase(it);
		return val;
	}

	int top() {
		return s.top();
	}

	int peekMax() {
		return *begin(ms);
	}

	int popMax() {
		int oldmax = *begin(ms);
		stack<int> temp;
		while (1) {
			int x = s.top();
			s.pop();
			if (x == oldmax)break;
			temp.push(x);
		}
		ms.erase(begin(ms));
		while (!temp.empty()) {
			s.push(temp.top());
			temp.pop();
		}
		return oldmax;
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