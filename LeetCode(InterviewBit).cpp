#define pb push_back
class Solution {
public:
	string addBinary(string a, string b) {
		int n = static_cast<int>(a.size());
		int m = static_cast<int>(b.size());
		if (n == 0)return b;
		if (m == 0)return a;
		int i = n - 1, j = m - 1, carry = 0;
		string result = "";
		while (i >= 0 && j >= 0) {
			int res = (a[i] - '0') + (b[j] - '0') + carry;
			result.pb((res % 2) + '0');
			carry = res / 2;
			--i, --j;
		}
		while (i >= 0) {
			int res = (a[i] - '0') + carry;
			result.pb((res % 2) + '0');
			carry = res / 2;
			--i;
		}
		while (j >= 0) {
			int res = (b[j] - '0') + carry;
			result.pb((res % 2) + '0');
			carry = res / 2;
			--j;
		}
		while (carry) {
			result.pb((carry % 2) + '0');
			carry >>= 1;
		}
		reverse(begin(result), end(result));
		return result;
	}
};

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int l = static_cast<int>(tasks.size());
		if (l == 0)return 0;
		if (n == 0)return l;
		if (l == 1)return 1;
		list<pair<char, int>> pile;
		int i = 1;
		char prev = tasks.front();
		int c = 1;
		while (i < l) {
			char current = tasks.at(i);
			if (current == prev)++c;
			else {
				pile.push_back(make_pair(prev, c));
				c = 1;
			}
			prev = current, ++i;
		}
		pile.push_back(make_pair(prev, c));
		std::list<pair<char, int>>::iterator it = pile.begin();
		int res = 0;
		int sz = int(pile.size()) - 1;
		while (it != end(pile)) {
			int consecutive = it->second;
			if (it->second == 1) {
				++res;
				++it;
				--sz;
			}
			else {
				if (sz == 0)res += n;
				else {
					--it->second;
					++res;
					auto it2 = std::next(it, 1);
					c = 0;
					int oldsz = min(sz, n);
					while (c++ < oldsz) {
						it2->second--;
						if (it2->second == 0)it2 = pile.erase(it2), --sz;
						else ++it2;
					}
					res += n;
				}
			}
		}
		return res;
	}
};

class Solution {
public:
	bool isMatch(string text, string pattern) {
		int n = text.size();
		int m = pattern.size();
		if (m == 0)
			return n == 0;
		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				// i ---> the remaining length of text
				// j ---> the remaining length of pattern
				if (i == 0 && j == 0)
					continue;
				// m-j --> the index of first character of remaining pattern
				// n-i  --> the index of first character of remaining text
				// dp[i][j] is true if pattern[m-j : ] and text[n-i : ] match
				bool first_match = i > 0 && j > 0 && ((pattern[m - j] == '.') || (pattern[m - j] == text[n - i]));
				if (j >= 2 && pattern[m - j + 1] == '*') {
					dp[i][j] = dp[i][j - 2] || (first_match && dp[i - 1][j]);
				}
				else {
					dp[i][j] = first_match && dp[i - 1][j - 1];
				}
			}
		}
		return dp[n][m];
	}
};

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		map<int, int, greater<int>> m;
		int n = int(nums.size());
		if (n == 0)return vector<int>{};
		for (int i = 0; i < min(k, n); ++i)++m[nums[i]];
		vector<int> result;
		result.push_back(begin(m)->first);
		for (int i = k; i < n; ++i) {
			int front_ = nums[i - k];
			int tail_ = nums[i];
			--m[front_];
			if (m[front_] == 0)m.erase(front_);
			++m[tail_];
			result.push_back(begin(m)->first);
		}
		return result;
	}
};