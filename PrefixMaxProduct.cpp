// you can use includes, for example:
#include <algorithm>
#include<unordered_map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using ll = unsigned long long int;
#define M 1000000000
int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	int l = static_cast<int>(S.length());
	if (l == 0)return 0;
	string prefix("");
	int c = 0;
	int res = 0;
	for (int i = 0; i < l; ++i) {
		prefix += S[i];
		++c;
		if (c == l)res = max(res, int(prefix.size()));
		else {
			int occ(1);
			string::size_type pos = 1, poso = 1;
			while (1) {
				pos = S.find(prefix, poso);
				if (pos == string::npos)break;
				++occ;
				++pos;
				if (pos == static_cast<std::string::size_type>(l))break;
				poso = pos;
			}
			ll sub = static_cast<ll>(prefix.size())*static_cast<ll>(occ);
			//cout<<prefix<<" "<<occ<<endl;
			if (sub > M)return M;
			res = max(res, static_cast<int>(sub));
		}
	}
	return res;
}