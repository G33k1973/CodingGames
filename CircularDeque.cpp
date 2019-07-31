class MyCircularDeque {
protected:
	int *arr;
	int capacity;
	int front, rear;
	int curcap = 0;
public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		this->capacity = k;
		arr = new int[capacity]();
		this->front = this->rear = -1;
		this->curcap = this->capacity;
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (curcap == 0)return 0;
		if (front == -1) {
			--this->curcap;
			front = capacity - 1;
			rear = front;
			arr[capacity - 1] = value;
			return true;
		}
		else {
			--this->curcap;
			fron=(front-1+capacity)%capacity;
			arr[front] = value;
		}
		return 1;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (curcap == 0)return false;
		rear = (rear + 1) % capacity;
		if (front == -1)front = rear;
		--curcap;
		arr[rear] = value;
		return 1;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (front == -1)return false;
		front = (front + 1) % capacity;
		++curcap;
		if (curcap == capacity) {
			front = rear = -1;
		}
		return true;
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (rear == -1)return false;
		rear = (rear - 1 + capacity) % capacity;
		++curcap;
		if (curcap == capacity)front = rear = -1;
		return 1;
	}

	/** Get the front item from the deque. */
	int getFront() {
		if (front == -1)return -1;
		return arr[front];
	}

	/** Get the last item from the deque. */
	int getRear() {
		if (rear == -1)return -1;
		return arr[rear];
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return curcap == capacity;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return curcap == 0;
	}
};