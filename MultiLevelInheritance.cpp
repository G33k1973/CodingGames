{
//Initial Template for C++
#include <iostream>
using namespace std;
class student
{
protected:
	int roll_number;

public:
	void set_number(int a)
	{
		roll_number = a;
	}

	void display_number()
	{
		cout << roll_number << endl;
	}
};
//Position this line where user code will be pasted.
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		result student1;
		int n;
		cin >> n;
		student1.set_number(n);
		float temp[5];
		int i;

		for (i = 0; i < 5; i++)
			cin >> temp[i];

		student1.set_marks(temp);
		student1.display();
	}
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
class test : public student
{
protected:
	int marks;
	// Add set_marks() method here.
public:
	void set_marks(int * arr) {
		int SIZE_ = 5;
		int i = 0;
		(*this).marks = 0;
		while (i < SIZE_) {
			this->marks += *(arr + i);
			++i;
		}
	}
};
class result : public test
{
	// Add display() method here.
public:
	void display() {
		cout << this->marks << endl;
	}
};