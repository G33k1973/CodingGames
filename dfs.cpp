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
#define pb push_back
#define N 10
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

void dfs(int totcount,int* dig,int i,string& temp,string& res){
	if(totcount==0){
		if(temp>res)res=temp;
		return;
	}
	if(i==0){
		for(int j=2;j>=0;--j){
			if(dig[j]>0){
				--dig[j];
				temp.pb(j+'0');
				dfs(totcount-1,dig,i+1,temp,res);
				++dig[j];
				temp.pop_back();
			}
		}
	}
	else if(i==1){
		if(temp.front()=='2'){
			for(int j=3;j>=0;--j){
				if(dig[j]>0){
					--dig[j];
					temp.pb(j+'0');
					dfs(totcount-1,dig,i+1,temp,res);
					++dig[j];
					temp.pop_back();
				}
			}
		}
		else{
			for(int j=9;j>=0;--j){
				if(dig[j]>0){
					--dig[j];
					temp.pb(j+'0');
					dfs(totcount-1,dig,i+1,temp,res);
					++dig[j];
					temp.pop_back();
				}
			}
		}
	}
	else if(i==2){
		for(int j=5;j>=0;--j){
			if(dig[j]>0){
				--dig[j];
				temp.pb(j+'0');
				dfs(totcount-1,dig,i+1,temp,res);
				++dig[j];
				temp.pop_back();
			}
		}
	}
	else{
		for(int j=9;j>=0;--j){
			if(dig[j]>0){
				--dig[j];
				temp.pb(j+'0');
				dfs(totcount-1,dig,i+1,temp,res);
				++dig[j];
				temp.pop_back();
			}
		}
	}
	return;
}

string solve(const string& s) {
	int dig[10] = { 0 };
	for (auto& x : s) {
		if (isdigit(x))++dig[x - '0'];
	}
	string sub("");
	string res(4,'0');
	dfs(4,dig,0,sub,res);
	res.insert(2,1,':');
	return res;
}
string invalid("-1\n");
int main(int argc, char ** argv) {
	std::ifstream cases("TestCases.txt", ios::in);
	std::ofstream result("Master2.txt", ios::out);
	string s("");
	while (std::getline(cases, s)) {
		if (s.empty())break;
		if(IsValid(s)){
			result << solve(s) << endl << std::flush;
		}
		else{
			result<<invalid<<std::flush;
		}
	}
	cases.close();
	result.close();
	return 0;
}