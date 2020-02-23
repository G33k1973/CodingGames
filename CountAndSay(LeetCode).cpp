class Solution {
public:
	string countAndSay(int n) {
		vector<string> arr{ "1" };
		if (n == 0)return "";
		if (n == 1)return arr.front();
		for (int i = 2; i <= n; ++i) {
			string a = arr.front();
			int c = 1;
			string b = "";
			char x = a.front();
			for (int j = 1; j < (int)a.size(); ++j) {
				char y = a.at(j);
				if (y == x) {
					++c;
				}
				else {
					b += to_string(c);
					b += string(1, x);
					c = 1;
				}
				x = y;
			}
			b += to_string(c);
			b += string(1, x);
			arr.front() = b;
		}
		return arr.front();
	}
};