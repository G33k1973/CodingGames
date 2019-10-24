// you can use includes, for example:
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
void solve(vector<int>& arr, int n, vector<int>& result) {
	std::stack<int> ms;
	int i = n - 1;
	while (i >= 0) {
		while (!ms.empty() && arr[i] >= arr[ms.top()]) {
			ms.pop();
		}
		if (!ms.empty())result[i] = ms.top() - i;
		ms.push(i);
		--i;
	}
	std::reverse(begin(arr), end(arr));
	while (!ms.empty())ms.pop();
	i = n - 1;
	int j = 0;
	while (i >= 0) {
		while (!ms.empty() && arr[i] >= arr[ms.top()]) {
			ms.pop();
		}
		if (!ms.empty())result[j] = (result[j] > 0) ? (min(result[j], ms.top() - i)) : (ms.top() - i);
		ms.push(i);
		--i, ++j;
	}
	return;
}
vector<int> solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(A.size());
	vector<int> result(n, 0);
	if (n < 2)return result;
	solve(A, n, result);
	return result;
}
