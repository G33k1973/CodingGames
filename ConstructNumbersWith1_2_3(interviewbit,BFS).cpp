#define pb push_back
vector<int> Solution::solve(int A) {
	if (A == 0)return vector<int>{};
	if (A == 1)return vector<int>{1};
	if (A == 2)return vector<int>{1, 2};
	if (A == 3)return vector<int>{1, 2, 3};
	queue<string> pile;
	pile.push("1");
	pile.push("2");
	pile.push("3");
	int c(0);
	vector<int> a;
	while (!pile.empty()) {
		int sz = int(pile.size());
		int u = 0;
		while (u < sz) {
			string temp = pile.front();
			pile.pop();
			a.pb(std::stoi(temp));
			++c;
			pile.push(string(temp + "1"));
			pile.push(string(temp + "2"));
			pile.push(string(temp + "3"));
			if (c == A)break;
			++u;
		}
		if (c == A)break;
	}
	return a;
}
