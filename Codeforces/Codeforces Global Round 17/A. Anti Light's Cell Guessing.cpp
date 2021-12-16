/*
	group : Codeforces - Codeforces Global Round 17
	name : A. Anti Light's Cell Guessing.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Anti_Light_s_Cell_Guessing.cpp
	url : https://codeforces.com/problemset/problem/1610/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.12.2021 18:57:52 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	if(n==1 && m==1)cout<<0<<"\n";
	else if(n==1 || m==1)cout<<1<<"\n";
	else cout<<2<<"\n";
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
//	parsed : 16-December-2021 18:57:47 IST