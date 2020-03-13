#define M 10000003
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
#define sc static_cast<ll>
bool ispossible(ll sum, vector<ll>& px, vector<int>& C, int n, int B, int A, ll score, ll& best) {
	int i = 0, c = 0;
	ll sub = 0ULL;
	ll mx = 0ULL;
	while (i < n) {
		ll nxtscore = sc(C[i])*sc(B);
		if (sub + nxtscore <= score) {
			sub += nxtscore;
		}
		else {
			++c;
			mx = max(mx, sub);
			sub = nxtscore;
			if (sub > score)return false;
			if (c + 1 == A) {
				sub = sum - px[i];
				sub *= sc(B);
				if (sub > score)return false;
				mx = max(mx, sub);
				break;
			}
		}
		++i;
	}
	best = mx;
	return true;
}
int Solution::paint(int A, int B, vector<int> &C) {
	int n = int(C.size());
	if (n == 0)return 0;
	if (A >= n) {
		int mx = *max_element(begin(C), end(C));
		ll res = sc(mx)*sc(B);
		res %= M;
		return int(res);
	}
	ll sum = 0ULL;
	vector<ll> px(n, 0ULL);
	for (int i = 0; i < n; ++i) {
		px[i] = sum;
		sum += sc(C[i]);
	}
	ll low = 0ULL, high = sum * sc(B);
	if (A == 1) {
		high %= M;
		return int(high);
	}
	ll res = std::numeric_limits<ll>::max();
	while (low <= high) {
		ll middle = low + (high - low) / 2;
		//check if t_max>=middle || t_max<middle
		ll best = 0ULL;
		bool ans = ispossible(sum, px, C, n, B, A, middle, best);
		if (ans == true) {
			res = min(res, best);
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}
	return int(res%M);
}
