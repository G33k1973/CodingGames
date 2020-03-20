#include<bits/stdc++.h>
using namespace std;
// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
using ll = long long int;
#define sc static_cast<ll>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B) {
	// write your code in C++14 (g++ 6.2.0)
	assert(A <= B);
	ll res{ 0 };
	ll low = sc(A);
	ll high = sc(B);
	double lb = (-1. + sqrt(1. + 4.*low)) / 2.;
	double ub = (-1. + sqrt(1. + 4.*high)) / 2.;
	ll llb = sc(std::ceil(lb));
	ll lub = sc(std::ceil(ub));
	ll left = llb * (llb + 1);
	if (left > high)return 0;
	ll right = lub * (lub + 1);
	if (right > high)--lub;
	if (lub < llb)return 0;
	res = int(lub - llb + 1);
	return int(res);
}

int main(int argc, char **argv) {
	return 0;
}