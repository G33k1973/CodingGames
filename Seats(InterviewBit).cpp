#define M 10000003
#define ms(a,b) (((a%M)+(b%M))%M)
#define pb push_back
int Solution::seats(string A) {
	{
		vector<int> arr;
		for (int i = 0; i < A.length(); i++)
			if (A[i] == 'x')arr.push_back(i);
		long count = 0;
		int mid = arr.size() / 2;
		for (int i = 0; i < arr.size(); i++)
			count = (count + abs(arr[i] - arr[mid]) - abs(i - mid)) % 10000003;
		return count;
	}
	int l = static_cast<int>(A.length());
	if (l == 0)return 0;
	if (l == 1)return 0;
	vector<int> xpos;
	int i = 0;
	int nx = 0;
	while (i < l) {
		if (A[i] == 'x') {
			++nx;
			xpos.pb(i);
		}
		++i;
	}
	if (nx < 2)return 0;
	int middle = xpos.front() + (xpos.back() - xpos.front()) / 2;
	auto it = std::lower_bound(begin(xpos), end(xpos), middle);
	int j = static_cast<int>(it - begin(xpos));
	i = j - 1;
	int nextpos = *it - 1;
	int res = 0;
	while (i >= 0) {
		int moves = nextpos - xpos[i];
		res = ms(res, moves);
		--nextpos, --i;
	}
	i = j + 1, nextpos = *it + 1;
	while (i < nx) {
		int moves = xpos[i] - nextpos;
		res = ms(res, moves);
		++i, ++nextpos;
	}
	return res;
}