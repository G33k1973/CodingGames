void kthLargest(int arr[], int n, int k)
{
	// your code here
	typedef std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq pile;
	for (int i = 0; i < n; ++i) {
		int m = i + 1;
		int x = arr[i];
		pile.push({ x,i });
		if (m < k) {
			cout << "-1 ";
		}
		else {
			int min_;
			while (pile.size() > k) {
				pile.pop();
			}
			cout << pile.top().first << " ";
		}
	}
}