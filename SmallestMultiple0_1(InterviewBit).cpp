int GetRemainder(const std::string& s, int A) {
	int res = 0;
	for (auto& x : s) {
		res = (res * 10 + (x - '0')) % A;
	}
	return res;
}
bool IsGreater(string& a, string& b) {
	int n = int(a.size());
	int m = int(b.size());
	if (n < m)return false;
	if (n == m && a < b)return false;
	return true;
}
string Solution::multiple(int A) {
	if (A == 0)return "0";
	if (A == 1)return "1";
	string s = to_string(A);
	int l = int(s.size());
	int c0(0), c1(0);
	for (auto& x : s) {
		if (x == '0')++c0;
		else if (x == '1')++c1;
	}
	if ((c0 + c1) == l)return s;
	string t(1, '1');
	std::queue<string> pile;
	pile.push(t);
	while (1) {
		int sz = int(pile.size());
		int i = 0;
		while (i < sz) {
			string current = pile.front();
			pile.pop();
			if (IsGreater(current, s) && GetRemainder(current, A) == 0) {
				return current;
			}
			current.push_back('0');
			pile.push(current);
			current.pop_back();
			current.push_back('1');
			pile.push(current);
			++i;
		}
	}
	return "";
}
