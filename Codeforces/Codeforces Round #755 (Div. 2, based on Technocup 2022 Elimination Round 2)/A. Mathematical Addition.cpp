/*
	group : Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
	name : A. Mathematical Addition.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Mathematical_Addition.cpp
	url : https://codeforces.com/contest/1589/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.11.2021 11:39:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int u,v;
	cin>>u>>v;

	cout<<u*u<<" "<<-v*v;
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
//	parsed : 14-November-2021 11:35:34 IST