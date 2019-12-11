class PhoneDirectory {
protected:
	std::vector<int> arr;
	int n;
public:
	/** Initialize your data structure here
		@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
	PhoneDirectory(int maxNumbers) {
		if (maxNumbers > 0) {
			arr.assign(maxNumbers, -1);
		}
		(*this).n = maxNumbers;
	}

	/** Provide a number which is not assigned to anyone.
		@return - Return an available number. Return -1 if none is available. */
	int get() {
		for (int i = 0; i < n; ++i) {
			if (arr[i] == -1) {
				arr[i] = 1;
				return i;
			}
		}
		return -1;
	}

	/** Check if a number is available or not. */
	bool check(int number) {
		if (number >= n || number < 0)return false;
		return (arr[number] == -1);
	}

	/** Recycle or release a number. */
	void release(int number) {
		if (number >= n || number < 0)return;
		arr[number] = -1;
	}
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */