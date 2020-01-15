class MyCircularQueue {
protected:
	int front, tail, capacity, size;
	vector<int> arr;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		front = -1, tail = -1;
		this->capacity = k;
		size = 0;
		arr.assign(capacity, -1);
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (size == capacity)return false;
		if (front == -1) {
			front = 0, tail = 0;
			++size;
			arr[front] = value;
			return true;
		}
		tail = (tail + 1) % capacity;
		++size;
		arr[tail] = value;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (size == 0)return false;
		--size;
		arr[front] = -1;
		front = (front + 1) % capacity;
		if (size == 0) {
			front = -1, tail = -1;
		}
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (size == 0)return -1;
		return arr[front];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (size == 0)return -1;
		return arr[tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return size == capacity;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */