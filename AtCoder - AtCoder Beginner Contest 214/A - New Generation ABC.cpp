/*
	group : AtCoder - AtCoder Beginner Contest 214
	name : A - New Generation ABC.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_New_Generation_ABC.cpp
	url : https://atcoder.jp/contests/abc214/tasks/abc214_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.08.2021 17:30:34 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	if(n<=125)cout<<4;
	else if(n<=211)cout<<6;
	else cout<<8;
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
//	parsed : 14-August-2021 17:30:17 IST