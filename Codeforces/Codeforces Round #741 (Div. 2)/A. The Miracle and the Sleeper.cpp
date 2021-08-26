/*
	group : Codeforces - Codeforces Round #741 (Div. 2)
	name : A. The Miracle and the Sleeper.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_The_Miracle_and_the_Sleeper.cpp
	url : https://codeforces.com/contest/1562/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.08.2021 20:08:01 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int l,r;
	cin>>l>>r;

	int z=(r+1)/2;
	if(z>=l){
		cout<<z-1<<"\n";
		return;
	}
	cout<<r%l<<"\n";
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
//	parsed : 26-August-2021 20:05:14 IST