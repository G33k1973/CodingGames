#define pb push_back
class Solution {
protected:
	int res;
	unordered_set<string> seen;
	void parse(string& a) {
		int l = int(a.size());
		auto pos = a.find('@');
		std::string::size_type i = 0;
		string mail("");
		while (i < pos) {
			char x = a.at(i++);
			if (x == '+')break;
			if (x == '.')continue;
			mail.pb(x);
		}
		mail += a.substr(pos);
		seen.insert(mail);
		return;
	}
public:
	int numUniqueEmails(vector<string>& emails) {
		int l = int(emails.size());
		if (l == 0)return 0;
		int res = 0;
		for (auto& x : emails) {
			parse(x);
		}
		return res=static_cast<int>(seen.size());
	}
};