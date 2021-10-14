/*
	group : Codeforces - Codeforces Round #748 (Div. 3)
	name : D1. All are Same.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D1_All_are_Same.cpp
	url : https://codeforces.com/contest/1593/problem/D1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.10.2021 20:16:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);

	for(int &x: v)cin>>x;

	sort(v.begin(),v.end());

	
	int g=0;
	for(int i=1;i<n;i++){
		v[i]-=v[0];
		g=gcd(g,v[i]);
	}

	if(g==0){
		cout<<"-1\n";
		return;
	}

	cout<<g<<"\n";

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
//	parsed : 14-October-2021 20:16:01 IST