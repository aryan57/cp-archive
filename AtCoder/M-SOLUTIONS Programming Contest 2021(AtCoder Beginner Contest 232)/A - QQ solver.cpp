/*
	group : AtCoder - M-SOLUTIONS Programming Contest 2021(AtCoder Beginner Contest 232)
	name : A - QQ solver.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_QQ_solver.cpp
	url : https://atcoder.jp/contests/abc232/tasks/abc232_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 19.12.2021 17:30:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	cout<<((s[0]-'0')*((s[2]-'0')));
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
//	parsed : 19-December-2021 17:30:45 IST