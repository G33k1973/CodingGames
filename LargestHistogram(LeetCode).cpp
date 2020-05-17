using ll = long long int;
#define sc static_cast<ll>
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)return 1;
		if (x == 0)return 0;
		bool negexp = (n < 0);
		ll EXP = sc(n);
		if (negexp)EXP = -EXP;
		bool negvalue = (x < 0 && (EXP & 1));
		x = -x;
		double res = exp(EXP*log(x));
		if (negexp)res = 1. / res;
		if (negvalue)res = -res;
		return res;
	}
};

class Solution {
public:
	int largestRectangleArea(vector<int>& h) {
		int n = int(h.size());
		if (!n)return 0;
		if (n == 1)return h.front();
		vector<int> right(n, -1);
		stack<int> ms;
		int i = n - 1;
		while (i >= 0) {
			while (!ms.empty() && h[i] <= h[ms.top()])ms.pop();
			if (!ms.empty())right[i] = ms.top();
			ms.push(i);
			--i;
		}
		while (!ms.empty())ms.pop();
		reverse(h.begin(), h.end());
		i = n - 1;
		vector<int> left(n, -1);
		while (i >= 0) {
			while (!ms.empty() && h[i] <= h[ms.top()])ms.pop();
			if (!ms.empty())left[n - 1 - i] = n - 1 - ms.top();
			ms.push(i);
			--i;
		}
		reverse(begin(h), end(h));
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int LEFT = left[i], RIGHT = right[i];
			int sub = 0;
			if (LEFT == -1)sub += i * h[i];
			else sub += (i - LEFT - 1)*h[i];
			if (RIGHT == -1)sub += (n - 1 - i)*h[i];
			else sub += (RIGHT - i - 1)*h[i];
			sub += h[i];
			res = max(res, sub);
		}
		return res;
	}
};