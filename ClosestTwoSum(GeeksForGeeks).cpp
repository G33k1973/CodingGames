pair<int, int> Max_Sum(int arr[], int n, int k)
{
	// return the pair
	if (n < 2)return make_pair(0, 0);
	sort(arr, arr + n);
	if (k == 0) {
		auto it = std::lower_bound(arr, arr + n, 0);
		if (it == (arr + n)) {
			return make_pair(arr[n - 2], arr[n - 1]);
		}
		if (it == arr)return make_pair(0, 0);
		--it;
		if (it == arr)return make_pair(0, 0);
		int x = *it;
		--it;
		int y = *it;
		return make_pair(y, x);
	}
	pair<int, int> ans(0, 0);
	int i, j;
	for (i = 0; i < n - 1; ++i) {
		int x = arr[i];
		if (x > 0 && x >= k)break;
		int tg = k - x;
		auto it = lower_bound(arr + i + 1, arr + n, tg);
		if (it == (arr + n)) {
			--it;
			int y = *it;
			if (x + y > ans.first + ans.second)ans = make_pair(x, y);
		}
		--it;
		int dist = int(it - arr);
		if (dist == i)continue;
		int y = *it;
		if (x + y > ans.first + ans.second)ans = make_pair(x, y);
	}
	return ans;
}