#define pb push_back
#define MAXAMOUNT 1000
class Solution {
protected:
	vector<string> res;
	struct Trans {
		string name;
		int time, amount;
		string city;
		string tr;
		Trans() {}
		Trans(string& a, int b, int c, string& d, string& s) :name(a), time(b), amount(c), city(d) {
			tr = s;
		}
	};
	vector<struct Trans> arr;
	unordered_set<string> badones;
	struct Trans parse(string& s) {
		Trans current;
		string temp(s);
		s += ",";
		string::size_type pos = 0, poso = 0;
		int l = int(s.size());
		string a, b;
		int c, d;
		int cnt(0);
		while (1) {
			pos = s.find(',', poso);
			string sub = s.substr(poso, pos - poso);
			if (cnt == 0) {
				a = sub;
			}
			else if (cnt == 1) {
				c = std::stoi(sub);
			}
			else if (cnt == 2) {
				d = std::stoi(sub);
				if (d > MAXAMOUNT) {
					badones.insert(temp);
					res.pb(temp);
				}
			}
			else if (cnt == 3) {
				b = sub;
			}
			++pos, ++cnt;
			if (pos == l)break;
			poso = pos;
		}
		current.name = a, current.time = c, current.amount = d, current.city = b;
		current.tr = temp;
		return current;
	}
public:
	vector<string> invalidTransactions(vector<string>& transactions) {
		int n = static_cast<int>(transactions.size());
		if (n == 0)return res;
		for (auto& x : transactions) {
			struct Trans temp = parse(x);
			for (int i = 0; i < (int)arr.size(); ++i) {
				if (arr[i].name == temp.name&&arr[i].city != temp.city) {
					int difftime = abs(arr[i].time - temp.time);
					if (difftime <= 60) {
						if (badones.count(arr[i].tr) == 0) {
							badones.insert(arr[i].tr);
							res.pb(arr[i].tr);
						}
						if (badones.count(temp.tr) == 0) {
							badones.insert(temp.tr);
							res.pb(temp.tr);
						}
					}
				}
			}
			arr.pb(temp);
		}
		return res;
		return res;
	}
};