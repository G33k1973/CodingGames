using ll = unsigned long long int;
#define M 1000000007
#define MX 100000
#define pb push_back
#define ms(a,b) (((a%M)+(b%M))%M)
int Solution::solve(vector<int> &A, vector<vector<int> > &B) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(B.size());
	if (m == 0)return 0;
	ll num = 1ULL;
	vector<ll> arr;
	//unordered_set<ll> h;
	while (1) {
		ll sq = num * num;
		arr.pb(sq);
		//h.insert(sq);
		if (sq > MX)break;
		++num;
	}
	ll res = 0ULL;
	for (int i = 0; i < m; ++i) {
		int op = B[i].front();
		if (op == 1) {
			assert(B[i][2] <= MX);
			int index = B[i][1] - 1;
			assert(index >= 0 && index < n);
			A[index] = B[i][2];
		}
		else if (op == 2) {
			int l = B[i][1] - 1;
			l = max(l, 0);
			int r = B[i][2] - 1;
			r = min(r, n - 1);
			for (int j = l; j <= r; ++j) {
				int val = A[j];
				assert(val >= 0 && val <= MX);
				//if(h.count(val)>0)continue;
				auto it = lower_bound(begin(arr), end(arr), val);
				if (*it == val)continue;
				int diff1 = *it - val;
				--it;
				int diff2 = val - *it;
				res = ms(res, static_cast<ll>(min(diff1, diff2)));
			}
		}
	}
	return int(res);
}
