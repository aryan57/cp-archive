/*
	group : AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
	name : A - First Grid.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_First_Grid.cpp
	url : https://atcoder.jp/contests/abc229/tasks/abc229_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.11.2021 17:31:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s1,s2;
	cin>>s1>>s2;

	if(s1==".#" && s2=="#."){
		cout<<"No\n";
		return;
	}
	swap(s1,s2);
	if(s1==".#" && s2=="#."){
		cout<<"No\n";
		return;
	}

	cout<<"Yes";
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
//	parsed : 27-November-2021 17:30:40 IST