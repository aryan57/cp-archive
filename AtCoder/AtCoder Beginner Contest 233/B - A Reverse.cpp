/*
	group : AtCoder - AtCoder Beginner Contest 233
	name : B - A Reverse.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_A_Reverse.cpp
	url : https://atcoder.jp/contests/abc233/tasks/abc233_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.12.2021 17:31:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int l,r;
	cin>>l>>r;
	string s;
	cin>>s;
	reverse(s.begin()+l-1,s.begin()+r);
	cout<<s;
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
//	parsed : 25-December-2021 17:31:45 IST