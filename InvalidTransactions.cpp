/*Each transaction string transactions[i] consists of comma separated values representing the name, time (in minutes), amount, and city of the transaction.*/
#define pb push_back
class Solution {
protected:
	unordered_set<string> seen;
	struct Transaction {
		string trst;
		string name;
		string city;
		int time;
		int amount;
		Transaction() {}
		Transaction(string& a) :trst(a) {
			a += ",";
			int l = int(a.size());
			int i = 0;
			string sub("");
			int c = 0;
			while (i < l) {
				char x = a[i++];
				if (x == ',') {
					if (c == 0) {
						this->name = sub;
					}
					else if (c == 1) {
						this->time = std::stoi(sub);
					}
					else if (c == 2) {
						this->amount = std::stoi(sub);
					}
					else if (c == 3) {
						this->city = sub;
					}
					++c;
					sub.clear();
					if (c == 4)break;
				}
				else
					sub.push_back(x);
			}
		}
	};
	vector<struct Transaction> arr;
	vector<string> res;
	void Add(string& s) {
		Transaction temp(s);
		if (temp.amount > 1000) {
			seen.insert(temp.trst);
			res.push_back(temp.trst);
		}
		if (arr.size() > 0) {
			for (const auto& x : arr) {
				if (x.name == temp.name&&x.city != temp.city) {
					int dff = abs(x.time - temp.time);
					if (dff <= 60) {
						if (seen.count(x.trst) == 0) {
							seen.insert(x.trst);
							res.push_back(x.trst);
						}
						if (seen.count(temp.trst) == 0) {
							seen.insert(temp.trst);
							res.push_back(temp.trst);
						}
					}
				}
			}
		}
		arr.push_back(temp);
	}
public:
	vector<string> invalidTransactions(vector<string>& transactions) {
		for (auto& x : transactions) {
			Add(x);
		}
		return res;
	}
};