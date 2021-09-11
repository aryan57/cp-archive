/*
	group : AtCoder - AtCoder Beginner Contest 218
	name : A - Weather Forecast.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Weather_Forecast.cpp
	url : https://atcoder.jp/contests/abc218/tasks/abc218_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 11.09.2021 17:30:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	string s;
	cin>>s;

	s='#'+s;

	if(s[n]=='o')cout<<"Yes";
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
//	parsed : 11-September-2021 17:30:30 IST