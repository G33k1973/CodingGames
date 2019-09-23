class ZeroEvenOdd {
private:
	int i;
	int n;
	std::mutex mtx;
	std::condition_variable cv;
	bool zero_;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
		this->i = 0;
		zero_ = true;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		while (1) {
			std::unique_lock<std::mutex> lck(mtx);
			cv.wait(lck, [&]() {return zero_; });
			++this->i;
			if (this->i > n)break;
			printNumber(0);
			zero_ = !zero_;
			cv.notify_all();
		}
	}

	void even(function<void(int)> printNumber) {
		while (i <= n) {
			if (!(i & 1)) {
				std::unique_lock<std::mutex> lck(mtx);
				cv.wait(lck, [&]() {return (!zero_); });
				printNumber(i);
				zero_ = !zero_;
				cv.notify_all();
			}
		}
	}

	void odd(function<void(int)> printNumber) {
		while (i <= n) {
			if (i & 1) {
				std::unique_lock<std::mutex> lck(mtx);
				cv.wait(lck, [&]() {return (!zero_); });
				printNumber(i);
				zero_ = !zero_;
				cv.notify_all();
			}
		}
	}
};