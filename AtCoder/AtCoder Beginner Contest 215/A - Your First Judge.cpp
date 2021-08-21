/*
	group : AtCoder - AtCoder Beginner Contest 215
	name : A - Your First Judge.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Your_First_Judge.cpp
	url : https://atcoder.jp/contests/abc215/tasks/abc215_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.08.2021 17:30:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	cout << ((s=="Hello,World!")? "AC" : "WA");
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
//	parsed : 21-August-2021 17:30:13 IST