std::mutex mtx;
std::condition_variable cv;

class FizzBuzz {
private:
	int n;
	int m;
public:
	FizzBuzz(int n) {
		this->n = n;
		this->m = 1;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		while (m <= n) {
			if ((m % 5 != 0) && (m % 3 == 0)) {
				std::unique_lock<std::mutex> lck(mtx);
				printFizz();
				++m;
				cv.notify_all();
			}
		}
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		while (m <= n) {
			if ((m % 3 != 0) && (m % 5 == 0)) {
				std::unique_lock<std::mutex> lck(mtx);
				printBuzz();
				++m;
				cv.notify_all();
			}
		}
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		while (m <= n) {
			if ((m % 3 == 0) && (m % 5 == 0)) {
				std::unique_lock<std::mutex> lck(mtx);
				printFizzBuzz();
				++m;
				cv.notify_all();
			}
		}
	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		while (m <= n) {
			if ((m % 3 != 0) && (m % 5 != 0)) {
				std::unique_lock<std::mutex> lck(mtx);
				printNumber(m);
				++m;
				cv.notify_all();
			}
		}
	}
};