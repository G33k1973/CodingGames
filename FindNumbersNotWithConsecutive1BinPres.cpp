class Solution {
public:
	int findIntegers(int num) {
		string s("");
		int x = num;
		while (x) {
			int rem = x % 2;
			s.push_back(rem + '0');
			x /= 2;
		}
		reverse(begin(s), end(s));
		int m = (int)s.size();
		if (num == 1)return 2;
		if (num == 2)return 3;
		if (num == 3)return 3;
		if (num == 4)return 4;
		if (num == 5)return 5;
		int res = 1;
		std::queue<string> pile;
		pile.push(string(1, '1'));
		while (!pile.empty()) {
			int sz = (int)pile.size();
			res += sz;
			int i = 0;
			while (i < sz) {
				string temp = pile.front();
				pile.pop();
				char x = temp.back();
				int l = (int)temp.size();
				if (l + 1 < m) {
					if (x == '0') {
						temp.push_back('0');
						pile.push(temp);
						temp.pop_back();
						temp.push_back('1');
						pile.push(temp);
					}
					else if (x == '1') {
						temp.push_back('0');
						pile.push(temp);
					}
				}
				else if (l + 1 == m) {
					if (temp < s) {
						temp += "0";
						if (temp <= s)pile.push(temp);
						temp.pop_back();
						if (x == '0') {
							temp += "1";
							if (temp <= s)pile.push(temp);
						}
					}
				}
				++i;
			}
		}
		return res;
	}
};