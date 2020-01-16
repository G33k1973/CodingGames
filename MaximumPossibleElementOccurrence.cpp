vector<int> Solution::solve(vector<int> &A, int B) {
	int n = int(A.size());
	if (n == 0)return vector<int>{};
	if (n == 1)return vector<int>{1, A.front()};
	std::map<int, int> h;
	for (auto& x : A)++h[x];
	pair<int, int> ans{ 0,INT_MIN };
	auto ptr = h.begin();
	while (ptr != end(h)) {
		int freq = ptr->second;
		if (freq > ans.first) {
			ans = make_pair(freq, ptr->first);
		}
		if (ptr != begin(h)) {
			auto ptr2 = std::prev(ptr, 1);
			int av = B;
			while (1) {
				int dist = ptr->first - ptr2->first;
				if (dist > av)break;
				int subfreq = ptr2->second;
				int psop = min(subfreq*dist, av) / dist;
				av -= dist * psop;
				freq += psop;
				if (ptr2 == begin(h))break;
				--ptr2;
			}
		}
		if (freq > ans.first) {
			ans = make_pair(freq, ptr->first);
		}
		++ptr;
	}
	return vector<int>{ans.first, ans.second};
}
