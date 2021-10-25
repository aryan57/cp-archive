/*
	group : Codeforces - Codeforces Round #750 (Div. 2)
	name : A. Luntik and Concerts.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Luntik_and_Concerts.cpp
	url : https://codeforces.com/contest/1582/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.10.2021 10:50:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;

	if(c%2==1 && a%2==0){
		cout<<1<<"\n";
		return;
	}

	if(c%2==0  && a%2==1){
		cout<<1<<"\n";
		return;
	}

	cout<<0;
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
//	parsed : 25-October-2021 10:49:57 IST