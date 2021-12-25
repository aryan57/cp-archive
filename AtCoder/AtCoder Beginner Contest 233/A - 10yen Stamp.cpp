/*
	group : AtCoder - AtCoder Beginner Contest 233
	name : A - 10yen Stamp.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_10yen_Stamp.cpp
	url : https://atcoder.jp/contests/abc233/tasks/abc233_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.12.2021 17:31:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int x,y;
	cin>>x>>y;
	if(x>=y)cout<<0;
	else {
		cout<<(y-x+9)/10;
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
//	parsed : 25-December-2021 17:30:12 IST