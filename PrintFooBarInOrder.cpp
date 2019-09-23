#include <iostream>
#include <future>

using namespace std;

class FooBar {
private:
	int					m_iter;
	bool				m_bFooTurn;
	mutex				m_lk;
	condition_variable	m_cv;

public:
	FooBar(int n) {
		m_iter = n;
		m_bFooTurn = true;
	}

	void foo(function<void()> printFoo) {
		for (int i = 0; i < m_iter; i++) {
			unique_lock<mutex> lk(m_lk);
			m_cv.wait(lk, [&] {return m_bFooTurn; });
			printFoo();
			m_bFooTurn = false;
			m_cv.notify_one();
		}
	}

	void bar(function<void()> printBar) {
		for (int i = 0; i < m_iter; i++) {
			unique_lock<mutex> lk(m_lk);
			m_cv.wait(lk, [&] {return !m_bFooTurn; });
			printBar();
			m_bFooTurn = true;
			m_cv.notify_one();
		}
	}
};