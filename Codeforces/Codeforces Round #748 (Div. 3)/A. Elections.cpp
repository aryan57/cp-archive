/*
	group : Codeforces - Codeforces Round #748 (Div. 3)
	name : A. Elections.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Elections.cpp
	url : https://codeforces.com/contest/1593/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.10.2021 19:48:41 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;

	cout<<max({0ll,b+1-a,c+1-a})<<" ";
	cout<<max({0ll,a+1-b,c+1-b})<<" ";
	cout<<max({0ll,a+1-c,b+1-c})<<"\n";
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
//	parsed : 14-October-2021 19:48:07 IST