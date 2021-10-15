/*
	group : Codeforces - Codeforces Round #482 (Div. 2)
	name : A. Pizza, Pizza, Pizza!!!.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Pizza_Pizza_Pizza_.cpp
	url : https://codeforces.com/contest/979/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 10:53:34 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	n++;
	if(n==1)cout<<0;
	else if(n%2)cout<<n;
	else{
		cout<<n/2;
	}
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
//	parsed : 15-October-2021 10:51:07 IST