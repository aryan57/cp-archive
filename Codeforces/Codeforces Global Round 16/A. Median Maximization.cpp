/*
	group : Codeforces - Codeforces Global Round 16
	name : A. Median Maximization.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Median_Maximization.cpp
	url : https://codeforces.com/contest/1566/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 12.09.2021 20:07:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,s;
	cin>>n>>s;

	int l = (n+1)/2;
	int r=n;

	cout<<s/(r-l+1);
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
//	parsed : 12-September-2021 20:07:36 IST