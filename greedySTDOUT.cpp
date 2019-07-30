#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

bool IsValid(const std::string& s){
	int c02=0,c69=0;
	int c2=0,c4=0,c3=0;
	for(const auto& x: s){
		char y=x;
		if(isdigit(y)){
			int val=y-'0';
			if(val>=0&&val<=2){
				++c02;
				if(val==2)++c2;
			}
			else if(val>=6)++c69;
			else if(val==4)++c4;
			else if(val==3)++c3;
		}
	}
	return (c02>2||(c02==2&&(c2==0||(c2>1&&c69<2)||(c2==1&&c69<3)))||(c02==1&&((c2==0&&c69<3)||(c2==1&&((c3==3)||(c3==1&&c69<2)||(c3==2&&c69<2))))));
}

string solve(const string& s) {
	int dig[10] = { 0 };
	for (auto& x : s) {
		if (isdigit(x))++dig[x - '0'];
	}
	int i, j, u, v;
	string sub("");
	string subm("");
	for (i = 2; i >= 0; --i) {
		if (sub.size())sub.clear();
		if (subm.size())subm.clear();
		int digcpy[10];
		memcpy(digcpy, dig, sizeof(dig));
		if (digcpy[i]) {
			--digcpy[i];
			sub += i + '0';
			for (j = 9; j >= 0; --j) {
				if (digcpy[j] > 0 && j >= 4 && i == 2)continue;
				if (digcpy[j] > 0) {
					--digcpy[j];
					sub += j + '0';
					break;
				}
			}
			if (sub.size() < 2) {
				continue;
			}
			for (u = 5; u >= 0; --u) {
				if (digcpy[u] > 0) {
					--digcpy[u];
					subm += u + '0';
					for (v = 9; v >= 0; --v) {
						if (digcpy[v] > 0) {
							subm += v + '0';
							break;
						}
					}
					break;
				}
			}
			if (subm.size() != 2)continue;
			break;
		}
	}
	string res = sub + ":" + subm;
	return res;
}
string invalid("-1\n");
int main(int argc, char ** argv) {
	string s("");
	std::getline(std::cin,s);
	if(IsValid(s)){
		cout << solve(s) << endl << std::flush;
	}
	else{
		cout<<invalid<<std::flush;
	}
	return 0;
}