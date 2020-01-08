int Solution::isNumber(const string A) {
	int l = int(A.size());
	if (l == 0)return 0;
	string B(A);
	while (B.size() > 0 && B.back() == ' ')B.pop_back();
	l = int(B.size());
	if (l == 0)return 0;
	if (B.back() == '.')return 0;
	int ce(0);
	int ndig(0);
	int ndots(0);
	int i = 0;
	char p = ' ';
	int totdig = 0;
	bool start = false;
	while (i < l) {
		char x = B.at(i++);
		if (isdigit(x)) {
			if (!start)start = true;
			++totdig;
			if (ndig == 0)++ndig;
			continue;
		}
		else if (x == 'e') {
			if (ndig == 0 || p == 'e')return 0;
			if (!start)start = true;
			ndig = 0;
			ndots = 0;
			++ce;
		}
		else if (x == '-' || x == '+') {
			if (ndig == 0 || p == 'e') {
				if (!start)start = true;
				continue;
			}
			return 0;
		}
		else if (x == '.') {
			if (ce > 0)return 0;
			++ndots;
			if (ndots > 1)return 0;
			if (!start)start = true;
			ndig = 0;
		}
		else if (x == ' ') {
			if (!start)continue;
			return 0;
		}
		else return 0;
		p = x;
	}
	return totdig > 0;
}
