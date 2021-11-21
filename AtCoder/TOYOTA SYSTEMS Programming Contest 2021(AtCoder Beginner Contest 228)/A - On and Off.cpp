/*
	group : AtCoder - TOYOTA SYSTEMS Programming Contest 2021(AtCoder Beginner Contest 228)
	name : A - On and Off.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_On_and_Off.cpp
	url : https://atcoder.jp/contests/abc228/tasks/abc228_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.11.2021 10:20:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int s,t,x;
	cin>>s>>t>>x;
	if(s<t && s<=x && x<t)cout<<"Yes\n";
	else if(s>t && s<=x || x<t)cout<<"Yes\n";
	else cout<<"No";
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
//	parsed : 21-November-2021 10:19:22 IST