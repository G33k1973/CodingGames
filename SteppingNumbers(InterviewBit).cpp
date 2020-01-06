#define pb push_back
using ll = long long int;
vector<int> sol;
void dfs(string& temp, ll cum, ll A, ll B) {
	if (cum >= A && cum <= B) {
		sol.pb(stoi(temp));
	}
	if (cum > B)return;
	char ld = temp.back();
	if (ld == '9') {
		temp.pb(ld - 1);
		dfs(temp, cum * 10LL + 8LL, A, B);
		temp.pop_back();
	}
	else if (ld == '0') {
		temp.pb(ld + 1);
		dfs(temp, cum * 10LL + 1LL, A, B);
		temp.pop_back();
	}
	else {
		temp.pb(ld + 1);
		int x = ld - '0';
		dfs(temp, cum * 10LL + static_cast<ll>(x + 1), A, B);
		temp.pop_back();
		temp.pb(ld - 1);
		dfs(temp, cum * 10LL + static_cast<ll>(x - 1), A, B);
		temp.pop_back();
	}
	return;
}
vector<int> Solution::stepnum(int A, int B) {
	if (sol.empty() ^ 1)sol.clear();
	if (A == 0)sol.pb(0);
	for (int i = 1; i <= 9; ++i) {
		string s(1, i + '0');
		dfs(s, static_cast<ll>(i), A, B);
	}
	std::sort(begin(sol), end(sol), less<int>());
	return sol;
}