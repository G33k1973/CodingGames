#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
ll cnt;
void Merge(vector<int>& arr, int l, int m, int h) {
	int n1 = m - l + 1;
	int n2 = h - m;
	vector<int> a(n1, 0), b(n2, 0);
	for (int i = 0; i < n1; ++i) {
		a[i] = arr[l + i];
	}
	for (int j = 0; j < n2; ++j) {
		b[j] = arr[m + 1 + j];
	}
	int i = 0, j = 0, k = l;
	while (i < n1&&j < n2) {
		if (a[i] <= b[j]) {
			arr[k++] = a[i++];
		}
		else {
			cnt = ms(cnt, static_cast<ll>(m + 1 - i - l));
			arr[k++] = b[j++];
		}
	}
	while (i < n1)arr[k++] = a[i++];
	while (j < n2)arr[k++] = b[j++];
}
void MergeSort(vector<int>& A, int l, int h) {
	if (l < h) {
		int m = l + (h - l) / 2;
		MergeSort(A, l, m);
		MergeSort(A, m + 1, h);
		Merge(A, l, m, h);
	}
	return;
}
int Solution::solve(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n < 2)return 0;
	cnt = 0;
	MergeSort(A, 0, n - 1);
	return int(cnt);
}
