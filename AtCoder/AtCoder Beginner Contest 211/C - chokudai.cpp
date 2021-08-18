/*
	group : AtCoder - AtCoder Beginner Contest 211
	name : C - chokudai.cpp
	srcPath : /home/aryan/cp-gedit/C_chokudai.cpp
	url : https://atcoder.jp/contests/abc211/tasks/abc211_c
*/
#include <bits/stdc++.h>
using namespace std;
const int32_t M = 1e9 + 7;
const int32_t inf = 1e9;

#define int long long

signed main()
{
    string s;
	cin>>s;
	
	int n=s.size();
	
	int dp[26];
	fill_n(&dp[0],26,0);
	
	string z ="chokudai";
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<8;j++){
		
			if(s[i]==z[j]) {
				if(j==0)dp[z[j]-'a']+=1;
				else if(i>0)dp[z[j]-'a']+=dp[z[j-1]-'a'];
				
				dp[z[j]-'a']%=M;
			}
		}
		
	}
	
	cout<<dp[8];
    return 0;
}
//	parsed : 24-July-2021 19:43:42 IST