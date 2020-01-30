#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return true;
	vector<int> B(A);
	sort(begin(B), end(B));
	vector<int> C;
	int i = 0, j = 0;
	while (i < n) {
		int x = A[i];
		if (x == B[j]) {
			++j;
			if (j == n)return 1;
			++i;
			continue;
		}
		if (C.size()>0 && C.back() == B[j]) {
			j++;
			C.pop_back();
			if (j == n)return 1;
		}
		C.push_back(x);
		if (C.back() == B[j]) {
			j++;
			C.pop_back();
			if (j == n)return 1;
		}
		++i;
	}
	while(!C.empty() && j != n && C.back() == B[j]) {
		j++;
		C.pop_back();
		if (j == n)return 1;
	}
	return 0;
}

int main() {
	vector<int> A{ 5, 2, 1, 4, 3 };
	int res = solve(A);
	return 0;
}
