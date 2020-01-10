int GetFromBinaryString(string& s) {
	int res = 0;
	int l = int(s.size());
	int j = l - 1;
	int i = 1;
	while (j >= 0) {
		if (s[j] == '1') {
			res += i;
		}
		i <<= 1;
		--j;
	}
	return res;
}
vector<int> Solution::grayCode(int A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if (A == 0)return vector<int>{};
	if (A == 1)return vector<int>{0, 1};
	vector<string> arr;
	arr.push_back("0");
	arr.push_back("1");
	for (int i = 2; i < (1 << A); i <<= 1) {
		for (int j = i - 1; j >= 0; --j) {
			arr.push_back(arr[j]);
		}
		for (int j = 0; j < i; ++j) {
			arr[j] = "0" + arr[j];
		}
		for (int j = i; j < i * 2; ++j) {
			arr[j] = "1" + arr[j];
		}
	}
	vector<int> result;
	for (auto& x : arr)result.push_back(GetFromBinaryString(x));
	return result;
}
