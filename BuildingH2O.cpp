class H2O {
private:
	int n;
	std::mutex mtx;
	std::condition_variable cv;
public:
	H2O() {
		this->n = 1;
	}

	void hydrogen(function<void()> releaseHydrogen) {

		// releaseHydrogen() outputs "H". Do not change or remove this line.
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck, [&]() {return (n % 3) != 0; });
		releaseHydrogen();
		++n;
		cv.notify_all();
	}

	void oxygen(function<void()> releaseOxygen) {

		// releaseOxygen() outputs "O". Do not change or remove this line.
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck, [&]()->bool {return (n % 3) == 0; });
		releaseOxygen();
		++n;
		cv.notify_all();
	}
};