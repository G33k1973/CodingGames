std::mutex mtx;
std::condition_variable cv;
class Foo {
private:
	int m;
public:
	Foo() {
		m = 1;
	}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		while (m < 4) {
			if (m == 1) {
				std::unique_lock<std::mutex> lck(mtx);
				printFirst();
				++m;
				cv.notify_all();
			}
		}
	}

	void second(function<void()> printSecond) {
		while (m < 4) {
			if (m == 2) {
				std::unique_lock<std::mutex> lck(mtx);
				printSecond();
				++m;
				cv.notify_all();
			}
		}
	}

	void third(function<void()> printThird) {

		// printThird() outputs "third". Do not change or remove this line.
		while (m < 4) {
			if (m == 3) {
				std::unique_lock<std::mutex> lck(mtx);
				printThird();
				++m;
				cv.notify_all();
			}
		}
	}
};