string Solution::solve(int A) {
	int count(0);
	std::vector<int> arr(A, 0);
	std::iota(begin(arr), end(arr), 1);
	do {
		bool isgood = true;
		for (int i = 1; i < A; ++i) {
			for (int j = 0; j < i; ++j) {
				if (((arr[i] & arr[j]) == arr[i]) && arr[j] > arr[i]) {
					isgood = false;
					break;
				}
			}
			if (isgood == false)break;
		}
		if (isgood)++count;
	} while (next_permutation(begin(arr), end(arr)));
	return to_string(count);
}
