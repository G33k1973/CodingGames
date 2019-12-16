class Solution {
protected:
	unordered_set<int> seen;
public:
	bool isHappy(int n) {
		if (n == 1)return true;
		if (seen.count(n) > 0)return false;
		int nn = 0;
		seen.insert(n);
		while (n) {
			int rem = n % 10;
			nn += rem * rem;
			n /= 10;
		}
		return isHappy(nn);
	}
};