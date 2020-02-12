#define pb push_back
string Solution::solve(vector<string> &A, vector<string> &B) {
	int la = static_cast<int>(A.size());
	int lb = static_cast<int>(B.size());
	if (lb == 0)return "";
	if (la == 0) {
		return string(lb, '0');
	}
	string result(lb, '0');
	for (int i = 0; i < lb; ++i) {
		string fb = B.at(i);
		int n = int(fb.size());
		bool suc = false;
		for (string& j : A) {
			int m = int(j.size());
			if (m != n)continue;
			int u = 0, c = 0;
			while (u < n) {
				if (j[u] != fb[u]) {
					++c;
					if (c > 1)break;
				}
				++u;
			}
			if (c == 1) {
				suc = 1;
				break;
			}
		}
		if (suc)result[i] = '1';
	}
	return result;
}
