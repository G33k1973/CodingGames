// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S, int K) {
	// write your code in C++14 (g++ 6.2.0)
	int l = int(S.length());
	if (l == 1)return 0;
	int i, j, cl, res = 0;
	for (i = 0; i < l - 1; ++i) {
		int no = 0, nc = 0;
		for (j = i; j < l; ++j) {
			cl = j - i + 1;
			char x = S.at(j);
			if (x == '(')++no;
			else if (x == ')') {
				if (no > 0)--no;
				else ++nc;
			}
			if (!(cl & 1)) {
				int reversal = (no + nc) / 2 + no % 2;
				if (reversal <= K)res = max(res, cl);
			}
		}
	}
	return res;
}