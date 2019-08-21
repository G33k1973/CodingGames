bool ispossible(int A[], int N, int i, vector<bool>& visited, int cum, int& c) {
	if (cum == 0) {
		return true;
	}
	if (i == N)return false;
	int j = i;
	while (j < N&&visited[j] == true) {
		++j;
	}
	if (j >= N)return false;
	bool ans1 = ispossible(A, N, j + 1, visited, cum, c);
	if (ans1)return 1;
	bool ans2 = false;
	if (A[j] <= cum) {
		visited[j] = true;
		++c;
		ans2 = ans2 || ispossible(A, N, j + 1, visited, cum - A[j], c);
		if (ans2)return 1;
		--c;
		visited[j] = false;
	}
	return ans1 || ans2;
}

bool Solve(int A[], int N, int k, int K, int target, vector<bool>& visited, int& c) {
	if (k == K) {
		if (c == N)return true;
		return false;
	}
	bool ans1 = ispossible(A, N, 0, visited, target, c);
	if (ans1)ans1 = ans1 && Solve(A, N, k + 1, K, target, visited, c);
	return ans1;
}

bool RecurUtil(int A[], int N, int K, int target) {
	vector<bool> visited(N, false);
	int c = 0;
	return Solve(A, N, 0, K, target, visited, c);
}

bool isKPartitionPossible(int A[], int N, int K)
{
	//Your code here
	int sum = 0;
	int i = 0;
	for (i = 0; i < N; ++i)sum += *(A + i);
	if (sum%K != 0)return false;
	int val = sum / K;
	return RecurUtil(A, N, K, val);
}

/*You are required to complete this method */
bool partition(vector<int> p, int A[], int r, int s)
{
	if (r < 0)
		return true;

	int x = A[r];
	r--;

	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] + x <= s)
		{
			p[i] += x;

			if (partition(p, A, r, s))
				return true;

			p[i] -= x;
		}

		if (p[i] == 0)
			break;
	}

	return false;
}

bool isKPartitionPossible(int A[], int N, int K)
{
	//Your code here

	sort(A, A + N);

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += A[i];

	if (sum % K != 0)
		return false;

	int r = N - 1;
	int s = sum / K;

	if (A[N - 1] > s)
		return false;

	int n = K;

	while (A[r] == s)
	{
		r--;
		K--;
	}

	vector<int> p;

	for (int i = 0; i < K; i++)
		p.push_back(0);

	return partition(p, A, r, s);
}