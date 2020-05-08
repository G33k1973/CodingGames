class FreqStack {
private:
	std::unordered_map<int, int> h;
	std::map<int, int> freq;
	std::stack<int> st;
public:
	FreqStack() {

	}

	void push(int x) {
		auto it = h.find(x);
		st.push(x);
		if (it == end(h)) {
			h.insert(make_pair(x, 1));
			++freq[1];
		}
		else {
			int oldfreq = it->second;
			auto it2 = freq.find(oldfreq);
			--it2->second;
			if (it2->second == 0)it2 = freq.erase(it2);
			++it->second;
			++freq[it->second];
		}
	}

	int pop() {
		assert(!st.empty());
		auto ptr = std::prev(freq.end(), 1);
		int maxfreq = ptr->first;
		std::stack<int> temp;
		while (1) {
			if (h[st.top()] == maxfreq)break;
			temp.push(st.top());
			st.pop();
		}
		int x = st.top();
		st.pop();
		while (!temp.empty()) {
			st.push(temp.top());
			temp.pop();
		}
		--ptr->second;
		if (ptr->second == 0)ptr = freq.erase(ptr);
		--h[x];
		if (h[x] == 0)h.erase(x);
		else ++freq[h[x]];
		return x;
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */