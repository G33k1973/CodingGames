class Solution {
private:
	bool isIPv4(string x) {
		x += "#";
		string sub = "";
		int cds = 0, cdots = 0;
		char prev = '#';
		for (const char& y : x) {
			if (y == '#') {
				if (sub.size() > 3 || sub.empty())return false;
				int x = stoi(sub);
				if (x < 0 || x>255)return false;
				++cds;
				break;
			}
			if (isdigit(y)) {
				sub.push_back(y);
				if (sub.size() == 2 && sub.front() == '0')return false;
			}
			else if (ispunct(y)) {
				if (ispunct(prev))return false;
				if (sub.size() > 3 || sub.empty())return false;
				int x = stoi(sub);
				if (x < 0 || x>255)return false;
				sub = "";
				++cds;
				++cdots;
			}
			else return false;
			prev = y;
		}
		return cdots == 3 && cds == 4;
	}
	bool isValidHex(string x) {
		if (x.size() > 4)return false;
		for (char& y : x) {
			if (isdigit(y))continue;
			if (isupper(y))y += 32;
			if (y > 'f')return false;
		}
		return true;
	}
	bool isIPv6(string x) {
		x += "#";
		string sub = "";
		char prev = '#';
		int cols = 0, cex = 0;
		for (const char& y : x) {
			if (y == '#') {
				if (sub.empty() || !isValidHex(sub))return false;
				++cex;
				break;
			}
			if (ispunct(y)) {
				if (ispunct(prev))return false;
				if (sub.empty() || !isValidHex(sub))return false;
				++cex;
				sub = "";
				++cols;
			}
			else if (isalnum(y)) {
				sub += string(1, y);
				//if(sub.size()==2&&prev=='0'&&y=='0')return false;
			}
			prev = y;
		}
		return cols == 7 && cex == 8;
	}
public:
	string validIPAddress(string IP) {
		if (isIPv4(IP))return "IPv4";
		if (isIPv6(IP))return "IPv6";
		return "Neither";
	}
};