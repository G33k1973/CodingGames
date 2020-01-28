using ll = unsigned long long int;
string Solution::solve(string A, int B) {
	int n = static_cast<int>(A.size());
	if (n == 0)return "";
	if (n == 1) {
		if (B != 1)return "";
		return string(1, A.front());
	}
	ll limit = static_cast<ll>(B);
	ll acclen = 0ULL;
	string sub = "";
	int i = 0;
	ll num = 0ULL;
	A += " ";
	while (i <= n) {
		if (!isdigit(A[i])) {
			if (num > 0 && sub.size() > 0) {
				ll subsum = static_cast<ll>(sub.size())*num;
				ll totalsize = acclen + subsum;
				if (totalsize < limit) {
					acclen = totalsize;
					sub.clear();
					num = 0;
				}
				else if (totalsize >= limit) {
					ll overtake = limit - acclen;
					char ch = sub[(overtake - 1) % sub.size()];
					return string(1, ch);
				}
			}
			sub.push_back(A[i]);
			++i;
			continue;
		}
		else {
			num = num * 10ULL + static_cast<ll>(A[i] - '0');
		}
		++i;
	}
	return "";
}
