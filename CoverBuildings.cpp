// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#define pb push_back
using ll = unsigned long long int;
#define sc static_cast<ll>
ll solution(vector<int> &H) {
	// write your code in C++14 (g++ 6.2.0)
	int n = int(H.size());
	if (n == 0)return 0;
	if (n == 1)return H[0];
	map<int, vector<int>, greater<int>> bst;
	for (int i = 0; i < n; ++i) {
		bst[H[i]].pb(i);
	}
	auto ptr = begin(bst);
	ll res = 0;
	if (ptr->second.front() == 0) {
		int j = ptr->second.back();
		int dist1 = j + 1;
		res += sc(dist1) * sc(ptr->first);
		auto ptr2 = next(ptr);
		while (ptr2 != end(bst)) {
			auto it = std::upper_bound(begin(ptr2->second), end(ptr2->second), j);
			if (it != end(ptr2->second)) {
				res += sc(n - j - 1)*sc(ptr2->first);
				break;
			}
			++ptr2;
		}
		return res;
	}
	ll pos1 = 0, pos2 = 0;
	ll pos3 = std::numeric_limits<ll>::max();
	//possibility 1: cover to the right
	int i = ptr->second.front();
	int dist1 = n - i;
	ll sub1 = sc(ptr->first)*sc(dist1);
	pos1 = sub1;
	auto ptr2 = next(ptr, 1);
	while (ptr2 != end(bst)) {
		if (ptr2->second.front() < i) {
			pos1 += sc(i) * (ptr2->first);
			break;
		}
		++ptr2;
	}
	//possibility2: cover to the left
	pos2 = sc(ptr->first)*sc(ptr->second.back() + 1);
	//cout<<pos2<<endl;
	ptr2 = next(ptr, 1);
	int j = ptr->second.back();
	while (ptr2 != end(bst)) {
		auto it = upper_bound(begin(ptr2->second), end(ptr2->second), j);
		if (it != end(ptr2->second)) {
			pos2 += sc(n - j - 1)*sc(ptr2->first);
			break;
		}
		++ptr2;
	}
	ptr2 = next(ptr, 1);
	while (ptr2 != end(bst)) {
		ll sub = numeric_limits<ll>::max();
		auto it = std::lower_bound(ptr2->second.begin(), ptr2->second.end(), i);
		int low, high;
		bool inside = false;
		if (it != end(ptr2->second) && *it <= j) {
			low = i, high = j;
			if (ptr2->second.front() >= i && ptr2->second.back() <= j)inside = true;
		}
		else if (it == end(ptr2->second)) {
			low = ptr2->second.back();
			if (low + 1 == i) {
				int m = int(ptr2->second.size());
				int k = m - 2;
				int prev = low;
				while (k >= 0) {
					if (ptr2->second[k] != (prev - 1))break;
					prev = ptr2->second[k];
					--k;
				}
				if (k < 0)inside = true, low = ptr2->second.front();
			}
			high = j;
		}
		else if (*it > j) {
			low = i;
			high = ptr2->second.front();
			if (high == (j + 1)) {
				int m = int(ptr2->second.size());
				int k = 1;
				int prev = high;
				while (k < m) {
					if (ptr2->second[k] != (prev + 1)) {
						break;
					}
					prev = ptr2->second[k];
					++k;
				}
				if (k == m)inside = true, high = ptr2->second.back();
			}
		}
		//cout<<low<<" "<<high<<endl;
		auto ptr3 = next(ptr2, 1);
		if (ptr3 != end(bst) && inside) {
			int Hdiff = ptr->first - ptr3->first;
			sub = sc(high - low + 1)*sc(Hdiff) + sc(n)*sc(ptr3->first);
			//cout<<sub<<" "<<low<<" "<<high<<endl;
		}
		else {
			int Hdiff = ptr->first - ptr2->first;
			sub = sc(high - low + 1)*sc(Hdiff) + sc(n)*sc(ptr2->first);
		}
		//++ptr2;
		//cout<<sub<<" "<<low<<" "<<high<<endl;
		pos3 = min(pos3, sub);
		break;
	}
	//cout<<pos1<<" "<<pos2<<" "<<pos3<<endl;
	return min(pos1, min(pos2, pos3));
}