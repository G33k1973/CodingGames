#include<bits/stdc++.h>
using namespace std;
#define CHARS 255
vector<int> solve(string A, string B) {
	cout << A << " " << B << endl;
	int n = int(A.length());
	int m = int(B.length());
	if (m == 0 || n == 0 || (m > n))return vector<int>{};
	vector<int> hB(255 + 1, 0);
	for (auto& x : B)++hB[x];
	vector<int> hA(255 + 1, 0);
	int start = 0, i = 0;
	vector<int> result;
	while (i < n) {
		char y = A[i];
		//cout << "Start is " << start << endl;
		if (hB[y] == 0) {
			//cout << "Fail at index " << i << endl;
			hA.assign(CHARS + 1, 0);
			start = i + 1;
			++i;
			continue;
		}
		if (hA[y] < hB[y]) {
			++hA[y];
			//cout << "Newest length is : " << i - start + 1 << endl;
			if (i - start + 1 == m) {
				result.push_back(start);
				--hA[A[start]];
				++start;
				++i;
				continue;
			}
			++i;
		}
		else if (hA[y] == hB[y]) {
			while (hA[y] == hB[y]) {
				--hA[A[start]];
				++start;
			}
			++hA[y];
			++i;
		}
	}
	return result;
}

int main() {
	string A("hblzqhrswn"), B("blzqh");
	vector<int> res = solve(A, B);
	for (auto& x : res)cout << x << " ";
	return 0;
}