/*
	group : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
	name : A. A Variety of Operations.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_A_Variety_of_Operations.cpp
	url : https://codeforces.com/contest/1556/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.08.2021 20:07:49 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b;
	cin>>a>>b;

	if(a%2!=b%2){
		cout<<"-1\n";
		return;
	}

	if(a==b && a==0){
		cout<<0;
	} else if(a==b){
		cout<<1;
	}else cout<<2;

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
//	parsed : 29-August-2021 20:05:42 IST