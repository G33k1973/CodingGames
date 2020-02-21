#define pb push_back
#define mp make_pair
pair<int, int> GetVal(const std::vector<int>& arr, int n, int target, int fa, int C) {
	int l = 0, h = n - 1;
	int m;
	pair<int, int> temp{ INT_MAX,INT_MIN };
	int diff;
	while (l <= h) {
		m = l + (h - l) / 2;
		diff = abs(arr[m] + fa - C);
		if (arr[m] == target) {
			return mp(0, target);
		}
		else if (arr[m] > target) {
			if (diff < temp.first)temp = mp(diff, arr[m]);
			h = m - 1;
		}
		else if (arr[m] < target) {
			if (diff < temp.first)temp = mp(diff, arr[m]);
			l = m + 1;
		}
	}
	return temp;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
	int n = int(A.size());
	int m = int(B.size());
	if (n == 0 || m == 0)return vector<int>{};
	int i = 0;
	pair<int, pair<int, int>> res{ INT_MAX,{INT_MIN,INT_MIN} };
	while (i < n) {
		int x = A[i];
		int target = C - A[i];
		pair<int, int> temp = GetVal(B, m, target, x, C);
		if (temp.first == 0)return vector<int>{x, target};
		if (temp.first < res.first) {
			res = mp(temp.first, mp(x, temp.second));
		}
		++i;
	}
	return vector<int>{res.second.first, res.second.second};
}
