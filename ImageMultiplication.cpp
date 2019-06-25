#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = unsigned long long int;
#define M 1000000007
#define LLMAX std::numeric_limits<ll>::max()
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1)res = (res%M + a % M) % M;
		b >>= 1;
		a = (a << 1) % M;
	}
	return (res%M);
}
struct bst {
	ll x;
	bst * left, *right;
	bst() {
		x = 0;
		left = right = NULL;
	}
	bst(ll y) :x(y) {
		this->left = this->right = 0;
	}
};

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int e;
		cin >> e;
		bst * root = NULL;
		std::unordered_map<ll, bst*> memo;
		for (int i = 0; i < e; ++i) {
			ll a, b;
			char c;
			cin >> a >> b >> c;
			bst * temp = NULL;
			if (root == NULL) {
				root = new bst(a);
				temp = root;
				memo[a] = root;
			}
			else {
				temp = memo[a];
			}
			if (c == 'R') {
				temp->right = new bst(b);
				memo[b] = temp->right;
			}
			else if (c == 'L') {
				temp->left = new bst(b);
				memo[b] = temp->left;
			}
		}
		std::queue<pair<bst*, int>> pile;
		pile.push({ root,0 });
		ll res = mul(root->x, root->x);
		int level = 1;
		while (!pile.empty()) {
			int sz = (int)pile.size();
			int szlevel = 1 << level;
			vector<ll> arr(szlevel, LLMAX);
			for (int i = 0; i < sz; ++i) {
				pair<bst*, int> temp = pile.front();
				pile.pop();
				int index = temp.second;
				bst* node = temp.first;
				if (node->left) {
					arr[2 * index] = (node->left->x);
					pile.push({ node->left,2 * index });
				}
				if (node->right) {
					arr[2 * index + 1] = (node->right->x);
					pile.push({ node->right,2 * index + 1 });
				}
			}
			int l = 0, h = szlevel - 1;
			while (l < h) {
				ll num1 = arr[l++];
				ll num2 = arr[h--];
				if (num1 == LLMAX || num2 == LLMAX)continue;
				ll sub = mul(num1, num2);
				res = (res%M + sub % M) % M;
			}
			++level;
		}
		cout << res << endl;
	}
	return 0;
}