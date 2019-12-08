#define pb push_back
class Solution {
protected:
	int n;
	unordered_map<int, int> h;
public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		n = static_cast<int>(nums.size());
		int maxelem = INT_MIN;
		int maxsum = 0;
		for (auto& x : nums) {
			if (x > maxelem)maxelem = x;
			maxsum += x;
			if (h.count(x) == 0) {
				h.insert(make_pair(x, 1));
			}
			else {
				++h[x];
			}
		}
		int minsum = n;//achieved by dividing with maxelem
		//maxsum is achieved by dividing with minelem
		int mindiv = 1, maxdiv = maxelem;
		int res = INT_MAX;
		while (mindiv <= maxdiv) {
			int m = mindiv + (maxdiv - mindiv) / 2;
			int sub = 0;
			for (auto& x : h) {
				int parsub = static_cast<int>(ceil(1.*x.first / (1.*m)));
				sub += x.second*parsub;
			}
			//cout<<m<<" "<<sub<<endl;
			if (sub <= threshold) {
				res = min(res, m);
				maxdiv = m - 1;
			}
			else {
				mindiv = m + 1;
			}
		}
		return res;
	}
};