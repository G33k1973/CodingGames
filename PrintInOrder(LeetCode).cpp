std::mutex mtx;
std::condition_variable cv;

class Foo {
private:
	int m;
public:
	Foo() {
		m = 0;
	}

	void first(function<void()> printFirst) {

		// printFirst() outputs "first". Do not change or remove this line.
		std::unique_lock<std::mutex> lck(mtx);
		while (m != 0) {
			cv.wait(lck);
		}
		lck.unlock();
		printFirst();
		++m;
		cv.notify_all();
	}

	void second(function<void()> printSecond) {

		// printSecond() outputs "second". Do not change or remove this line.
		std::unique_lock<std::mutex> lck(mtx);
		while (m != 1) {
			cv.wait(lck);
		}
		lck.unlock();
		printSecond();
		++m;
		cv.notify_all();
	}

	void third(function<void()> printThird) {

		// printThird() outputs "third". Do not change or remove this line.
		std::unique_lock<std::mutex> lck(mtx);
		while (m != 2) {
			cv.wait(lck);
		}
		lck.unlock();
		printThird();
		++m;
		cv.notify_all();
	}
};