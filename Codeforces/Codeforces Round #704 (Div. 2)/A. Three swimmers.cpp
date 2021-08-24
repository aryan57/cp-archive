/*
	group : Codeforces - Codeforces Round #704 (Div. 2)
	name : A. Three swimmers.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Three_swimmers.cpp
	url : https://codeforces.com/contest/1492/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 24.08.2021 19:57:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int ceil(int a, int b)
{
	return (a + b - 1) / b;
}

void solve()
{
	int a,b,c,p;
	cin>>p>>a>>b>>c;

	int s1=a*ceil(p,a)-p;
	int s2=b*ceil(p,b)-p;
	int s3=c*ceil(p,c)-p;

	cout<<min({s1,s2,s3})<<"\n";
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
//	parsed : 24-August-2021 19:55:20 IST