/*
	group : AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
	name : A - Distinct Strings.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Distinct_Strings.cpp
	url : https://atcoder.jp/contests/abc225/tasks/abc225_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.10.2021 17:30:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());

	if(s[0]!=s[1] && s[1]!=s[2])cout<<6;
	else if(s[0]==s[1] && s[1]==s[2])cout<<1;
	else cout<<3;
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
//	parsed : 30-October-2021 17:30:11 IST