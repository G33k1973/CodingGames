typedef std::priority_queue<int, vector<int>, less<int>> mxheap;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
int Solution::nchoc(int A, vector<int> &B) {
	int n = static_cast<int>(B.size());
	if (n == 0)return 0;
	if (A == 0)return 0;
	mxheap pile;
	for (auto& x : B) {
		pile.push(x);
	}
	int res = 0;
	while (!pile.empty() && A-- > 0) {
		int sub = pile.top();
		pile.pop();
		res = ms(res, sub);
		sub >>= 1;
		if (sub > 0)pile.push(sub);
	}
	return res;
}
