/*
	group : AtCoder - AtCoder Beginner Contest 224
	name : A - Tires.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Tires.cpp
	url : https://atcoder.jp/contests/abc224/tasks/abc224_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 17:30:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	if(s[n-2]=='e')cout<<"er";
	else cout<<"ist";
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
//	parsed : 23-October-2021 17:30:11 IST