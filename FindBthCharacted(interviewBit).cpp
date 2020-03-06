using ll = unsigned long long int;
#define sc static_cast<ll>
string Solution::solve(string A, int B) {
	int l = static_cast<int>(A.length());
	ll curlen = 0ULL;
	vector<pair<string, ll>> arr;
	int i = 0;
	string sub = "";
	ll len = 0ULL;
	while (i < l) {
		if (!isdigit(A[i])) {
			sub.push_back(A[i]);
			++curlen;
			len = curlen;
			if (curlen == B)return string(1, A[i]);
		}
		else {
			ll freq = 0ULL;
			while (i < l&&isdigit(A[i])) {
				freq = freq * 10ULL + sc(A[i] - '0');
				++i;
			}
			--i;
			arr.push_back(make_pair(sub, freq));
			curlen *= freq;
			if (curlen == sc(B))return string(1, sub.back());
			if (curlen > sc(B))break;
			sub.clear();
		}
		++i;
	}
	if (!isdigit(A.back()))arr.push_back(make_pair(sub, 1));
	ll j = (sc(B - 1) % len);
	ll k = 0;
	i = 0;
	int n = int(arr.size());
	ll sublen = 0;
	string temp("");
	while (i < n) {
		int current = int(arr[i].first.size());
		ll parlen = sc(current);
		sublen += parlen;
		ll freq = sc(arr[i].second);
		temp += arr[i].first;
		if (sublen*freq > sc(j)) {
			k = sc(j) % sublen;
			return string(1, temp[k]);
		}
		else {
			while (arr[i].second--) {
				temp += arr[i].first;
			}
		}
		++i;
	}
	return "";
}
