/* digits rotation */
#define pb push_back
class Solution {
protected:
	unordered_set<char> badones{ '3','4','7' };
	unordered_map<char, char> mapping{ {'0','0'},{'1','1'},{'8','8'},{'6','9'},{'9','6'},{'2','5'},{'5','2'} };
	bool isgood(int x) {
		string fx = to_string(x);
		string rot = "";
		for (auto& x : fx) {
			if (badones.count(x) > 0)return false;
			rot.pb(mapping[x]);
		}
		return rot.compare(fx) != 0;
	}
public:
	int rotatedDigits(int N) {
		int res = 0;
		for (int i = 1; i <= N; ++i) {
			if (isgood(i))++res;
		}
		return res;
	}
};

class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int n = static_cast<int>(seats.size());
		assert(n > 1);
		int res = -1;
		if (n == 2)return 1;
		int fl = -1;
		int j;
		for (int i = 0; i < n; ++i) {
			j = i;
			while (j < n&&seats[j] == 1) {
				fl = j, ++j;
			}
			if (j != i) {
				--j;
				i = j;
				continue;
			}
			while (j < n&&seats[j] == 0) {
				++j;
			}
			if (j == n)--j;
			if (fl == -1) {
				res = max(res, j);
			}
			else {
				if(j+1<n||seats[j]==1)res = max(res, (j - fl) / 2);
				else res = max(res, j - fl);
			}
			if(j+1!=n)--j;
			i = j;
		}
		return res;
	}
};