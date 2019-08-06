class Solution {
private:
	bool IsPossible(const std::vector<int>& piles, int K, int H) {
		int tot = 0;
		for (auto& x : piles) {
			if (x <= K)++tot;
			else {
				int rem = x % K;
				tot += x / K;
				if (rem != 0)++tot;
			}
			if (tot > H)return 0;
		}
		return 1;
	}
public:
	int minEatingSpeed(vector<int>& piles, int H) {
		int low = 1, high = 1000000000;
		int res = high;
		while (low <= high) {
			int middle = low + (high - low) / 2;
			if ((*this).IsPossible(piles, middle, H)) {
				res = min(res, middle);
				high = middle - 1;
			}
			else {
				low = middle + 1;
			}
		}
		return res;
	}
};