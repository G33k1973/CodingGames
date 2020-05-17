#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define mp make_pair
#define sc static_cast<ll>

unordered_map<std::string, int> seen;
map<vector<int>, int> seenrbt;
pair<vector<int>, bool> parse(string& s) {
	bool isgood = false;
	vector<int> a(10, 0);
	int c(0);
	for (auto& x : s) {
		int j = x - '0';
		if (a[j] == 0) {
			++a[j];
			++c;
		}
	}
	if (c == 10)isgood = !isgood;
	return make_pair(a, isgood);
}
struct TID {
	vector<int> a;
	bool isgood;
	int fr;
	TID() {
		this->isgood = false;
		fr = 0;
	}
	TID(pair<vector<int>, bool>& mypair) {
		this->a.assign(mypair.first.begin(), mypair.first.end());
		this->isgood = mypair.second;
		fr = 1;
	}
	TID(string& s) {
		this->fr = 1;
		a.assign(10, 0);
		int c = 0;
		this->isgood = false;
		for (auto& x : s) {
			int j = x - '0';
			if (a[j] == 0) {
				++a[j];
				++c;
			}
		}
		if (c == 10)isgood = !isgood;
	}
	TID& operator++() {
		++this->fr;
		return *this;
	}
	bool AreGoodTogether(const struct TID& obj) const {
		if (this->isgood || obj.isgood)return true;
		int c = 0;
		for (int i = 0; i < 10; ++i) {
			if (a[i] || obj.a[i])++c;
		}
		return (c == 10);
	}
};
ll count(ll freq) {
	return (freq & 1) ? (((freq - 1) / 2)*freq) : (((freq / 2)*(freq - 1)));
}
// Complete the winningLotteryTicket function below.
ll winningLotteryTicket(vector<string> tickets) {
	ll res = 0LL;
	int i{ -1 };
	vector<struct TID> arr;
	constexpr int faster = 1;
	for (auto& x : tickets) {
		if (faster == 0) {
			auto it = seen.find(x);
			if (it == end(seen)) {
				++i;
				seen.insert(mp(x, i));
				struct TID current(x);
				arr.pb(current);
			}
			else {
				++arr[it->second];
			}
		}
		else if (faster == 1) {
			std::pair<vector<int>, bool> temp = parse(x);
			auto it = seenrbt.find(temp.first);
			if (it == seenrbt.end()) {
				++i;
				seenrbt.insert(make_pair(temp.first, i));
				struct TID current(temp);
				arr.pb(current);
			}
			else {
				++arr[it->second];
			}
		}
	}
	i = 0;
	int j, n = int(arr.size());
	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			if (j == i && arr[j].isgood) {
				res += count(arr[j].fr);
			}
			else if (i != j && arr[i].AreGoodTogether(arr[j])) {
				res += arr[i].fr*arr[j].fr;
			}
		}
	}
	return res;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<string> tickets(n);

	for (int i = 0; i < n; i++) {
		string tickets_item;
		getline(cin, tickets_item);

		tickets[i] = tickets_item;
	}

	ll result = winningLotteryTicket(tickets);

	fout << result << "\n";

	fout.close();

	return 0;
}
