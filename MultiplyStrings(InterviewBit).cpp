#include<bits/stdc++.h>
using namespace std;
#define pb push_back

void RevStr(string& s,int low,int high) {
	while (low < high) {
		char temp = s[low];
		s[low] = s[high];
		s[high] = temp;
		++low, --high;
	}
}

string AddString(string& s1, string& s2) {
	int n = int(s1.size());
	int m = int(s2.size());
	if (n == 0)return s2;
	if (m == 0)return s1;
	int carry = 0, i = 0, j = 0;
	//RevStr(s1,0,n-1);
	//RevStr(s2,0,m-1);
	string z = "";
	while (i < n&&j < m) {
		int res = (s1[i] - '0') + (s2[j] - '0') + carry;
		z.pb((res % 10) + '0');
		++i, ++j;
		carry = res / 10;
	}
	while (i < n) {
		int res = (s1[i] - '0') + carry;
		z.pb((res % 10) + '0');
		++i;
		carry = res / 10;
	}
	while (j < m) {
		int res = (s2[j] - '0') + carry;
		z.pb((res % 10) + '0');
		++j;
		carry = res / 10;
	}
	while (carry) {
		z.pb((carry % 10) + '0');
		carry /= 10;
	}
	//RevStr(z, 0, int(z.size()) - 1);
	return z;
}

void mulsinglenumber(string& z,string& mul, int l, int x) {
	if (x == 0) {
		z = "0";
		return;
	}
	if (x == 1) {
		RevStr(mul, 0, l - 1);
		z+ = mul;
		return;
	}
	int carry = 0;
	int i = l - 1;
	while (i >= 0) {
		int res = (mul[i] - '0')*x + carry;
		z.pb((res % 10) + '0');
		carry = res / 10;
		--i;
	}
	while (carry) {
		z.pb((carry % 10) + '0');
		carry /= 10;
	}
	return;
}

string multiply(string A, string B) {
	int n = int(A.length());
	int m = int(B.length());
	if (n == 0)return B;
	if (m == 0)return A;
	vector<string> arr{ A,B };
	sort(begin(arr), end(arr), [&](const string& a, const string& b) {return a.size() > b.size(); });
	vector<string> collector;
	string mul = arr.front();
	string demul = arr.back();
	n = int(demul.size());
	int i = n - 1;
	int c = -1;
	int j = 0;
	while (i >= 0) {
		++c;
		string z = "";
		if (c > 0)z += string(c, '0');
		mulsinglenumber(z, mul, int(mul.size()), demul[i] - '0');
		//cout << z << endl;
		collector.pb(z);
		--i, ++j;
	}
	i = 0;
	string result = collector.at(0);
	while (i < j - 1) {
		result = AddString(result, collector[i + 1]);
		++i;
	}
	RevStr(result, 0, int(result.size()) - 1);
	return result;
}

int main(int argc, char ** argv) {
	string A = "99999";
		string B = "99999";
	cout << multiply(A, B);
	return 0;
}
