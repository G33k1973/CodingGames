/* You are required to complete this function
which return the required missing number
if present else return -1*/
string addone(string x) {
	int n = (int)x.size();
	string z("");
	int i = 0, c = 0;
	reverse(begin(x), end(x));
	while (i < n) {
		int fx = x[i] - '0';
		int res = fx + c;
		if (i == 0)++res;
		z.push_back((res % 10) + '0');
		c = res / 10;
		++i;
	}
	while (c) {
		z.push_back((c % 10) + '0');
		c /= 10;
	}
	reverse(begin(z), end(z));
	return z;
}
bool dfs(const string& str, int l, int i, string x, int c, string missing, string& res) {
	//cout<<x<<endl;
	if (i == l) {
		if (c == 0)return false;
		res = missing;
		return true;
	}
	bool ans = false;
	string y = addone(x);
	auto pos = str.find(y, i);
	if (pos != string::npos&&pos == i)ans = ans || dfs(str, l, i + (int)y.size(), y, c, missing, res);
	if (c == 0) {
		string z = addone(y);
		auto pos = str.find(z, i);
		if (pos != string::npos&&pos == i)ans = ans || dfs(str, l, i + (int)z.size(), z, c + 1, y, res);
	}
	return ans;
}
int missingNumber(const string& str)
{
	// Code here
	int l = static_cast<int>(str.size());
	if (l < 2)return -1;
	string s(""), res("");
	bool ans = false;
	for (int i = 0; i <= l / 2; ++i) {
		s.push_back(str[i]);
		string t("");
		ans = dfs(str, l, i + 1, s, 0, t, res);
		if (ans)break;
	}
	return (ans == false) ? (-1) : (std::stoi(res));
}