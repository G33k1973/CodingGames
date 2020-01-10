class MaxStack {
protected:
	std::multiset<int, greater<int>> ms;
	std::stack<int> s;
public:
	/** initialize your data structure here. */
	MaxStack() {

	}

	void push(int x) {
		ms.insert(x);
		s.push(x);
	}

	int pop() {
		int val = s.top();
		auto it = ms.find(val);
		it = ms.erase(it);
		s.pop();
		return val;
	}

	int top() {
		return s.top();
	}

	int peekMax() {
		return *begin(ms);
	}

	int popMax() {
		int x = *begin(ms);
		ms.erase(ms.find(x));
		std::stack<int> temp;
		while (1) {
			int y = s.top();
			if (y == x) {
				s.pop();
				break;
			}
			s.pop();
			temp.push(y);
		}
		while (!temp.empty()) {
			s.push(temp.top());
			temp.pop();
		}
		return x;
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