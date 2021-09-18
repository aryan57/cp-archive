/*
	group : AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest 219）
	name : B - Maritozzo.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Maritozzo.cpp
	url : https://atcoder.jp/contests/abc219/tasks/abc219_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.09.2021 17:33:12 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	vector <string> v(3);

	cin>>v[0]>>v[1]>>v[2];

	string t;
	cin>>t;

	for(char x : t)
	{
		cout<<v[x-'1'];
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
//	parsed : 18-September-2021 17:32:29 IST