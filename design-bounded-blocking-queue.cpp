class BoundedBlockingQueue {
protected:
	std::mutex mtx;
	std::condition_variable cv;
	int n;
	std::queue<int> pile;
public:
	BoundedBlockingQueue(int capacity) {
		this->n = capacity;
	}

	void enqueue(int element) {
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck, [&]() {return (int)pile.size() < n; });
		pile.push(element);
		cv.notify_all();
	}

	int dequeue() {
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck, [&]()->bool {return static_cast<int>(pile.size()) > 0; });
		int x = pile.front();
		pile.pop();
		cv.notify_all();
		return x;
	}

	int size() {
		return static_cast<int>(pile.size());
	}
};