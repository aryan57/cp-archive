/*
	group : Codeforces - Codeforces Round #761 (Div. 2)
	name : A. Forbidden Subsequence.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Forbidden_Subsequence.cpp
	url : https://codeforces.com/contest/1617/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.12.2021 19:07:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s,t;
	cin>>s>>t;

	string ss=s;
	sort(ss.begin(),ss.end());
	int cnt[3]={};
	int cnt2[3]={};
	string zz="";
	for(char x : ss){
		if(x<='c'){
			cnt[x-'a']=1;
			cnt2[x-'a']++;
		}else{
			zz+=x;
		}
	}

	if(cnt[0]+cnt[2]+cnt[1]!=3 || t!="abc"){
		cout<<ss;
		cout<<"\n";
		return;
	}

	while (cnt2[0]--)
	{
		cout<<'a';
	}
	while (cnt2[2]--)
	{
		cout<<'c';
	}
	while (cnt2[1]--)
	{
		cout<<'b';
	}

	cout<<zz;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 16-December-2021 19:05:08 IST