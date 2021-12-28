/*
	group : Codeforces - Codeforces Round #763 (Div. 2)
	name : A. Robot Cleaner.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Robot_Cleaner.cpp
	url : https://codeforces.com/contest/1623/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.12.2021 19:08:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	pair <int,int> s,t;
	cin>>s.first>>s.second;
	cin>>t.first>>t.second;

	int tt=0;
	int dr=1;
	int dc=1;
	while (s.first!=t.first && s.second!=t.second)
	{
		if(s.first+dr>n || s.first+dr<1)dr=-dr;
		if(s.second+dc>m || s.second+dc<1)dc=-dc;
		tt++;
		s.first+=dr;
		s.second+=dc;
	}
	cout<<tt<<"\n";
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
//	parsed : 28-December-2021 19:05:36 IST