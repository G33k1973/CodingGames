#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
int findElement(int arr[], vector<vector<int>>& ranges,
	int rotations, int index)
{
	for (int i = rotations - 1; i >= 0; i--) {

		// Range[left...right] 
		int left = ranges[i][0];
		int right = ranges[i][1];

		// Rotation will not have any effect 
		if (left <= index && right >= index) {
			if (index == left)
				index = right;
			else
				index--;
		}
	}

	// Returning new element 
	return arr[index];
}
void rotateRight(vector<int>&a, int l, int r, int k) {
	int n = (int)a.size();
	r = min(r, n - 1);
	int dist = r - l + 1;
	if (dist == 1)return;
	int num = k % dist;
	if (num == 0)return;
	int L = l, R = r;
	while (L < R) {
		std::swap(a[L++], a[R--]);
	}
	return;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, x, k;
		cin >> n >> x >> k;
		vector<int> a(n);
		for (auto& x : a)cin >> x;
		vector<vector<int>> ranges(k, vector<int>(2, -1));
		for (int i = 0; i < k; ++i) {
			int l, r;
			cin >> l >> r;
			ranges[i][0] = l;
			ranges[i][1] = r;
		}
		cout << findElement(a.data(), ranges, k, x) << "\n";
	}
	return 0;
}