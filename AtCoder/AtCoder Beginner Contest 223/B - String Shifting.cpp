/*
	group : AtCoder - AtCoder Beginner Contest 223
	name : B - String Shifting.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_String_Shifting.cpp
	url : https://atcoder.jp/contests/abc223/tasks/abc223_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.10.2021 10:52:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s,smn,smx;
	cin>>s;
	smn=s;
	smx=s;
	int n=s.size();
	int k=n+1;

	while(k--){
		smn=min(smn,s);
		smx=max(smx,s);
		rotate(s.begin(),s.begin()+1,s.end());
	}

	cout<<smn<<"\n"<<smx;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 21-October-2021 10:52:15 IST