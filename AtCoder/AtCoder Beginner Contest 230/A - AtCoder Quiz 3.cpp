/*
	group : AtCoder - AtCoder Beginner Contest 230
	name : A - AtCoder Quiz 3.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_AtCoder_Quiz_3.cpp
	url : https://atcoder.jp/contests/abc230/tasks/abc230_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.12.2021 17:31:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	if(n>=42)n++;

	string x = string(4,'0')+to_string(n);

	cout<<"AGC";
	cout<<x.substr(x.size()-3,3);
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
//	parsed : 03-December-2021 17:30:12 IST