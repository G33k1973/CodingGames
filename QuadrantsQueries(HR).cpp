#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quadrants' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY p
 *  2. STRING_ARRAY queries
 */
#define pb push_back
#define eb emplace_back
void quadrants(const vector<vector<int>>& p, const vector<string>& q) {
	const int l = int(p.size());
	vector<int> quad(l, -1);
	int i{ 0 };
	vector<int> px1(l + 1, 0),
		px2(l + 1, 0), px3(l + 1, 0),
		px4(l + 1, 0);
	for (auto& x : p) {
		int X = x.front();
		int Y = x.back();
		if (min(X, Y) > 0)
			quad[i++] = 1;//quad n. 1
		else if (X > 0 && Y < 0)
			quad[i++] = 4;//quad n. 4
		else if (X < 0 && Y>0)
			quad[i++] = 2;//quad n. 2
		else if (X < 0 && Y < 0)
			quad[i++] = 3;//quad n. 3
		if (quad[i - 1] == 1) {
			px1[i] = 1 + px1[i - 1];
			px2[i] = px2[i - 1];
			px3[i] = px3[i - 1];
			px4[i] = px4[i - 1];
		}
		else if (quad[i - 1] == 2) {
			px2[i] = 1 + px2[i - 1];
			px1[i] = px1[i - 1];
			px3[i] = px3[i - 1];
			px4[i] = px4[i - 1];
		}
		else if (quad[i - 1] == 3) {
			px3[i] = 1 + px3[i - 1];
			px2[i] = px2[i - 1];
			px1[i] = px1[i - 1];
			px4[i] = px4[i - 1];
		}
		else if (quad[i - 1] == 4) {
			px4[i] = 1 + px4[i - 1];
			px3[i] = px3[i - 1];
			px2[i] = px2[i - 1];
			px1[i] = px1[i - 1];
		}
	}
	struct obj {
		char ch;
		int s, e;
		obj() = default;
		obj(char x, int i, int j) {
			ch = x, s = i, e = j;
		}
		obj(const struct obj& other) = default;
		obj(struct obj&& other) = default;
		obj& operator=(const struct obj& other) = default;
		obj& operator=(struct obj&& other) = default;
	};
	auto get = [](const string& s) {
		string::size_type pos = 0;
		char x = s[0];
		pos += 2;
		auto pos2 = s.find(' ', pos);
		int s_ = stoi(s.substr(pos, pos2 - pos));
		pos = pos2 + 1;
		int e_ = stoi(s.substr(pos));
		obj temp = { x,s_,e_ };
		return temp;
	};
	i = 0;
	for (auto& x : q) {
		obj temp = get(x);
		int s = temp.s,
			e = temp.e;
		++i;
		/*
		if(i==8){
		cout<<"Start point : "<<s<<" End point : "<<e<<"\n";
		}
		*/
		if (temp.ch == 'C') {
			cout << px1[e] - px1[s - 1] << ' ' << px2[e] - px2[s - 1] << ' ' << px3[e] - px3[s - 1] << ' ' <<
				px4[e] - px4[s - 1] << '\n';
		}
		else if (temp.ch == 'X') {
			int u{ s };
			while (u <= e) {
				int i = u - 1;
				if (quad[i] == 1) {
					px1[i + 1] = px1[i];
					px4[i + 1] = 1 + px4[i];
					px3[i + 1] = px3[i];
					px2[i + 1] = px2[i];
					quad[i] = 4;
				}
				else if (quad[i] == 4) {
					px1[i + 1] = 1 + px1[i];
					px4[i + 1] = px4[i];
					px2[i + 1] = px2[i];
					px3[i + 1] = px3[i];
					quad[i] = 1;
				}
				else if (quad[i] == 2) {
					quad[i] = 3;
					px2[i + 1] = px2[i];
					px3[i + 1] = 1 + px3[i];
					px1[i + 1] = px1[i];
					px4[i + 1] = px4[i];
				}
				else if (quad[i] == 3) {
					quad[i] = 2;
					px2[i + 1] = 1 + px2[i];
					px3[i + 1] = px3[i];
					px1[i + 1] = px1[i];
					px4[i + 1] = px4[i];
				}
				++u;
			}
			if (u <= l) {
				while (u <= l) {
					if (quad[u - 1] == 1) {
						px1[u] = 1 + px1[u - 1];
						px2[u] = px2[u - 1];
						px3[u] = px3[u - 1];
						px4[u] = px4[u - 1];
					}
					else if (quad[u - 1] == 2) {
						px1[u] = px1[u - 1];
						px2[u] = 1 + px2[u - 1];
						px3[u] = px3[u - 1];
						px4[u] = px4[u - 1];
					}
					else if (quad[u - 1] == 3) {
						px1[u] = px1[u - 1];
						px2[u] = px2[u - 1];
						px3[u] = 1 + px3[u - 1];
						px4[u] = px4[u - 1];
					}
					else if (quad[u - 1] == 4) {
						px1[u] = px1[u - 1];
						px2[u] = px2[u - 1];
						px3[u] = px3[u - 1];
						px4[u] = 1 + px4[u - 1];
					}
					++u;
				}
			}
		}
		else if (temp.ch == 'Y') {
			int u{ s };
			while (u <= e) {
				int i = u - 1;
				if (quad[i] == 1) {
					px1[i + 1] = px1[i];
					px4[i + 1] = px4[i];
					px3[i + 1] = px3[i];
					px2[i + 1] = 1 + px2[i];
					quad[i] = 2;
				}
				else if (quad[i] == 4) {
					px1[i + 1] = px1[i];
					px4[i + 1] = px4[i];
					px2[i + 1] = px2[i];
					px3[i + 1] = 1 + px3[i];
					quad[i] = 3;
				}
				else if (quad[i] == 2) {
					quad[i] = 1;
					px2[i + 1] = px2[i];
					px3[i + 1] = px3[i];
					px1[i + 1] = 1 + px1[i];
					px4[i + 1] = px4[i];
				}
				else if (quad[i] == 3) {
					quad[i] = 4;
					px2[i + 1] = px2[i];
					px3[i + 1] = px3[i];
					px1[i + 1] = px1[i];
					px4[i + 1] = 1 + px4[i];
				}
				++u;
			}
			if (u <= l) {
				while (u <= l) {
					if (quad[u - 1] == 1) {
						px1[u] = 1 + px1[u - 1];
						px2[u] = px2[u - 1];
						px3[u] = px3[u - 1];
						px4[u] = px4[u - 1];
					}
					else if (quad[u - 1] == 2) {
						px1[u] = px1[u - 1];
						px2[u] = 1 + px2[u - 1];
						px3[u] = px3[u - 1];
						px4[u] = px4[u - 1];
					}
					else if (quad[u - 1] == 3) {
						px1[u] = px1[u - 1];
						px2[u] = px2[u - 1];
						px3[u] = 1 + px3[u - 1];
						px4[u] = px4[u - 1];
					}
					else if (quad[u - 1] == 4) {
						px1[u] = px1[u - 1];
						px2[u] = px2[u - 1];
						px3[u] = px3[u - 1];
						px4[u] = 1 + px4[u - 1];
					}
					++u;
				}
			}
		}
	}

	return;
}

int main()
{
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	vector<vector<int>> p(n);

	for (int i = 0; i < n; i++) {
		p[i].resize(2);

		string p_row_temp_temp;
		getline(cin, p_row_temp_temp);

		vector<string> p_row_temp = split(rtrim(p_row_temp_temp));

		for (int j = 0; j < 2; j++) {
			int p_row_item = stoi(p_row_temp[j]);

			p[i][j] = p_row_item;
		}
	}

	string q_temp;
	getline(cin, q_temp);

	int q = stoi(ltrim(rtrim(q_temp)));

	vector<string> queries(q);

	for (int i = 0; i < q; i++) {
		string queries_item;
		getline(cin, queries_item);

		queries[i] = queries_item;
	}

	quadrants(p, queries);

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
