class Solution {
public:
	int calculate(string s) {
		std::stack<pair<char, int>> ops;//operators
		std::stack<int> pars;//parenthesis
		int num = 0;
		std::stack<pair<int, int>> vals;//values
		s += " ";
		int l = int(s.size());
		if (l == 1)return 0;
		int i = 0;
		while (i < l) {
			bool loadvalue = false;
			int j = -1;
			while (isdigit(s[i])) {
				if (!loadvalue)loadvalue = !loadvalue;
				if (j == -1)j = i;
				num = num * 10 + (s[i] - '0');
				++i;
			}
			if (loadvalue) {
				vals.push({ num,j });
				num = 0;
				continue;
			}
			if (s[i] == '(') {
				pars.push(i);
			}
			else if (s[i] == '-' || s[i] == '+') {
				ops.push({ s[i],i });
			}
			else if (s[i] == ')') {
				j = pars.top();
				pars.pop();
				//x0 x1 x2
				// op1 op2
				vector<int> a;
				vector<char> b;
				while (!vals.empty() && vals.top().second > j) {
					a.push_back(vals.top().first);
					vals.pop();
				}
				while (!ops.empty() && ops.top().second > j) {
					b.push_back(ops.top().first);
					ops.pop();
				}
				if (a.empty())vals.push(make_pair(0, j));
				else {
					int res = 0;
					int n = int(a.size());
					if (n == 1) {
						vals.push(make_pair(a.front(), j));
					}
					else {
						reverse(begin(a), end(a));
						reverse(begin(b), end(b));
						int i = 0;
						while (i < n) {
							if (i == 0) {
								if (b[i] == '+')res = a[i] + a[i + 1];
								else if (b[i] == '-')res = a[i] - a[i + 1];
								i += 2;
							}
							else {
								if (b[i - 1] == '+')res += a[i];
								else res -= a[i];
								++i;
							}
						}
						vals.push(make_pair(res, j));
					}
				}
			}
			++i;
		}
		if (vals.size() > 1) {
			vector<int> a;
			vector<char> b;
			while (!vals.empty()) {
				a.push_back(vals.top().first);
				vals.pop();
			}
			while (!ops.empty()) {
				b.push_back(ops.top().first);
				ops.pop();
			}
			int res = 0;
			int n = int(a.size());
			//cout<<n<<endl;
			if (n == 1) {
				vals.push(make_pair(a.front(), 0));
			}
			else {
				reverse(begin(a), end(a));
				reverse(begin(b), end(b));
				int i = 0;
				while (i < n) {
					if (i == 0) {
						if (b[i] == '+')res = a[i] + a[i + 1];
						else if (b[i] == '-')res = a[i] - a[i + 1];
						i += 2;
					}
					else {
						if (b[i - 1] == '+')res += a[i];
						else res -= a[i];
						++i;
					}
					//cout<<res<<endl;
				}
				vals.push(make_pair(res, 0));
			}
		}
		return vals.top().first;
	}
};