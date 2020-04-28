class FirstUnique {
protected:
	std::unordered_map<int, int> h;
	std::list<int> unq;
public:
	FirstUnique(vector<int>& nums) {
		int n = int(nums.size());
		if (n > 0) {
			for (int& x : nums) {
				if (h.count(x) == 0) {
					h.insert(make_pair(x, 1));
					unq.push_back(x);
				}
				else {
					++h[x];
				}
			}
		}
	}

	int showFirstUnique() {
		if (unq.empty())return -1;
		for (int& x : unq) {
			if (h[x] == 1)return x;
		}
		return -1;
	}

	void add(int value) {
		auto it = h.find(value);
		if (it == end(h)) {
			unq.push_back(value);
			h[value] = 1;
		}
		else {
			++h[value];
		}
	}
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */