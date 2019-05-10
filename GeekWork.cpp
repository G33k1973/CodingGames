#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef unsigned long long int ll;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
vector<ll> catalan;
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a << 1) % M;
	}
	return (res%M);
}
void init(int n) {
	catalan.assign(n + 1, 0);
	catalan[0] = catalan[1] = 1;
	for (int i = 2; i <= n; ++i) {
		catalan.operator[](i) = 0;
		for (int j = 0; j < i; ++j) {
			catalan[i] = ms(catalan[i], mul(catalan[j], catalan[i - j - 1]));
		}
	}
	return;
}
int main(int argc, char * argv[]) {
	int q;
	cin >> q;
	int nx = 0;
	vector<int> a;
	while (q--) {
		int n;
		cin >> n;
		a.pb(n);
		if (nx < n)nx = n;
	}
	init(nx);
	for (const auto& x : a) {
		cout << catalan[x] << "\n";
	}
	return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int l = static_cast<int>(l);
		float sq_ = sqrt(1.*l);
		int num1 = static_cast<int>(std::floor(sq_));
		int num2 = static_cast<int>(std::ceil(sq_));
		int n, m;
		if (num1 == num2)n = m = num1;
		else {
			n = num1;
			m = num2;
		}
		std::vector<bool> visited(l, false);
		string res("");
		int i = 0;
		while (res.size()<l) {
			int j = i;
			for (; j < l; j += m) {
				res.push_back(s[j]);
			}
			++i;
		}
		res += "\n";
	}
	return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(int n, vector<int>& a, std::map<vector<int>, int>& uniques) {
	if (n == 0) {
		vector<int> b(a);
		sort(begin(b), end(b), greater<int>());
		auto it = uniques.find(b);
		if (it == end(uniques)) {
			for (auto& x : b)cout << x << " ";
			//cout<<endl;
			++uniques[b];
		}
		return;
	}
	for (int i = n; i > 0; --i) {
		a.push_back(i);
		dfs(n - i, a, uniques);
		a.pop_back();
	}
	return;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a;
		std::map<vector<int>, int> uniques;
		dfs(n, a, uniques);
		cout << endl;
	}
	return 0;
}
//LONGEST ARITHMETIC PROGRESSION
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f3f
int dfs(const std::vector<int>& a, int n, int i, int p, int AP) {
	//cout<<AP<<endl;
	if (i == n)return 0;
	int ans = 0;
	int ans1 = 0, ans2 = 0;
	for (int j = i; j < n; ++j) {
		if (AP == INF && j != p) {
			ans1 = max(ans1, 2 + dfs(a, n, j + 1, j, a[j] - a[p]));
		}
		else if (j != p && a[j] - a[p] == AP) {
			ans2 = max(1 + dfs(a, n, j + 1, j, AP), ans2);
		}
	}
	return ans = max(ans1, ans2);
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int res = 1;
		for (int i = 0; i < n - 1; ++i) {
			res = std::max(res, dfs(a, n, i + 1, i, INF));
		}
		cout << res << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;
int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int h[n];
		memset(h, -1, sizeof(h));
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (x != -1)h[x] = 1;
		}
		for (int i = 0; i < n; ++i) {
			if ((*(h + i)) == -1)cout << -1 << " ";
			else cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ui = unsigned int;
int GetSwBits_(ui x, ui num) {
	int sub = 0;
	for (ui i = 1 << 31; i > 0; i >>= 1) {
		if ((i & x) != (i & num)) {
			++sub;
		}
	}
	return sub;
}
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		ui x;
		sc = scanf("%d %u", &n, &x);
		std::pair<int, ui> ans(INT_MAX, 0);
		int i = 0;
		while (i < n) {
			ui y;
			sc = scanf("%u", &y);
			int sub = GetSwBits_(x, y);
			if (sub < ans.first) {
				ans = std::make_pair(sub, y);
			}
			++i;
		}
		printf("%d\n", ans.second);

	}
	return 0;
}

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long int;
#define pb push_back
vector<ll> coins_;
#define LLMAX std::numeric_limits<ll>::max()
void init(ll n, ll x) {
	if (!coins_.empty())coins_.clear();
	ll y = 1;
	int c = 1;
	while (y <= n) {
		coins_.pb(y);
		y *= x;
		++c;
		if (c > 12)break;
	}
}
int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll n, x;
		cin >> n >> x;
		init(n, x);
		sort(begin(coins_), end(coins_), greater<ll>());
		int m = coins_.size();
		int h[m];
		memset(&h[0], 0, sizeof(h));
		for (int j = 0; j < m; ++j) {
			if (coins_[j] <= n) {
				int fr = n / coins_[j];
				h[j] = fr;
				n -= coins_[j] * fr;
			}
		}
		ll res = std::accumulate(h, h + m, 0);
		cout << res << "\n";
	}
	return 0;
}

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int i, j, k, l;
		int res = 0;
		for (i = 1; i < n; ++i) {
			for (j = i; j < n; ++j) {
				if (i + j >= n)break;
				for (k = j; k < n; ++k) {
					if (i + j + k >= n)break;
					++res;
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long int;
ll GGCD(ll a, ll b) {
	if (a == 0)return b;
	return GGCD(b%a, a);
}
int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (auto& x : a)cin >> x;
		ll ans = a.front();
		for (int i = 1; i < n; ++i) {
			ans = (ans*a[i]) / GGCD(ans, a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
#define pb push_back
#define mp make_pair
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		std::unordered_map<int, int> X, Y;
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			++X[x];
			++Y[y];
		}
		int res = 0;
		for (auto& z : X) {
			if (z.second > 1) {
				int tot = z.second;
				res += ((tot & 1) ? (((tot - 1) / 2)*tot) : ((tot / 2)*(tot - 1)));
			}
		}
		for (auto& z : Y) {
			if (z.second > 1) {
				int tot = z.second;
				res += ((tot & 1) ? (((tot - 1) / 2)*tot) : ((tot / 2)*(tot - 1)));
			}
		}
		cout << res << "\n";
	}
	return 0;
}

#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision;
using namespace std;

cpp_int GetSeries(cpp_int n) {
	if (n == 1)return  6;
	if (n == 2)return 14;
	cpp_int diff = 4;
	cpp_int i = 2;
	cpp_int counter_ = 2;
	cpp_int prev_ = 14;
	cpp_int next_;
	while (counter_ < n) {
		next_ = prev_ * 3;
		diff += i;
		next_ -= diff;
		counter_++;
		i *= 2;
		prev_ = next_;
	}
	return next_;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		cpp_int n;
		cin >> n;
		cout << GetSeries(n) << "\n";
	}
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define M 1000000007
ll dfs(const std::string& s, int n, int i, string& t, std::unordered_set<string>& uniques) {
	if (i == n) {
		if (uniques.count(t) == 0) {
			uniques.insert(t);
			return 1;
		}
		return 0;
	}
	t.push_back(s[i]);
	ll ans1 = dfs(s, n, i + 1, t, uniques);
	t.pop_back();
	ll ans2 = dfs(s, n, i + 1, t, uniques);
	return ((ans1) % M + (ans2) % M) % M;
}
const int MAX_CHAR = 256;

// Returns count of distinct sunsequences of str. 
ll countSub(string str)
{
	// Create an array to store index 
	// of last 
	vector<int> last(MAX_CHAR, -1);

	// Length of input string 
	int n = str.length();

	// dp[i] is going to store count of distinct 
	// subsequences of length i. 
	ll dp[n + 1] = { 0 };

	// Empty substring has only one subsequence 
	dp[0] = 1;

	// Traverse through all lengths from 1 to n. 
	for (int i = 1; i <= n; i++)
	{
		// Number of subsequences with substring 
		// str[0..i-1] 
		dp[i] = (dp[i - 1] % M + dp[i - 1] % M) % M;

		// If current character has appeared 
		// before, then remove all subsequences 
		// ending with previous occurrence. 
		if (last[str[i - 1]] != -1)
			dp[i] = (dp[i] % M + M - dp[last[str[i - 1]]] % M) % M;

		// Mark occurrence of current character 
		last[str[i - 1]] = (i - 1);
	}

	return dp[n];
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		{
			ll res = countSub(s);
			cout << res << "\n";
			continue;
		}
		string t("");
		std::unordered_set<string> un;
		ll ans = dfs(s, s.size(), 0, t, un);
		cout << ans << "\n";
	}
	return 0;
}

//https://practice.geeksforgeeks.org/problems/maximum-value/0

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& x : a)cin >> x;
		if (n < 4) {
			cout << "-1\n";
			continue;
		}
		int ai = a[0], aj = a[1];
		int best = aj - ai;
		int mn = a[0];
		vector<int> FromLeft(n, 0);
		for (int i = 1; i < n - 2; ++i) {
			if (i == 1) {
				FromLeft[i] = aj - ai;
			}
			else {
				FromLeft[i] = std::max(best, a[i] - mn);
			}
			best = std::max(best, FromLeft[i]);
			mn = std::min(mn, a[i]);
		}
		reverse(begin(a), end(a));
		ai = a[0], aj = a[1];
		int mx = a[0];
		best = INT_MIN;
		vector<int> FromRight(n, 0);
		for (int i = 1; i < n - 2; ++i) {
			int j = n - i - 1;
			if (i == 1) {
				FromRight[j] = ai - aj;
			}
			else {
				FromRight[j] = std::max(best, mx - a[i]);
			}
			best = std::max(best, FromRight[j]);
			mx = std::max(mx, a[i]);
			//cout<<mx<<" "<<best<<endl;
		}
		int res = INT_MIN;
		for (int i = 1; i < n - 2; ++i) {
			//cout<<FromLeft[i]<<" "<<FromRight[i+1]<<"\n";
			res = std::max(res, FromLeft[i] + FromRight[i + 1]);
		}
		cout << res << endl;
	}
	return 0;
}