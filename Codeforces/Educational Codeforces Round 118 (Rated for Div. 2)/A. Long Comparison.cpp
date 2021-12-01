/*
	group : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
	name : A. Long Comparison.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Long_Comparison.cpp
	url : https://codeforces.com/contest/1613/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 01.12.2021 20:05:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int x1,x2,p1,p2;
	cin>>x1>>p1;
	cin>>x2>>p2;

	string zx1=to_string(x1);
	string zx2=to_string(x2);

	if(zx1.size() + p1 > zx2.size()+p2){
		cout<<">\n";
		return;
	}
	if(zx1.size() + p1 < zx2.size()+p2){
		cout<<"<\n";
		return;
	}

	int mn=min(p1,p2);
	int t1=p1-mn;
	while (t1--)
	{
		x1*=10;
	}
	int t2=p2-mn;
	while (t2--)
	{
		x2*=10;
	}
	if(x1 > x2){
		cout<<">\n";
		return;
	}
	if(x1 < x2){
		cout<<"<\n";
		return;
	}

	cout<<"=\n";
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
//	parsed : 01-December-2021 20:05:10 IST