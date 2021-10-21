/*
	group : AtCoder - AtCoder Beginner Contest 223
	name : A - Exact Price.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Exact_Price.cpp
	url : https://atcoder.jp/contests/abc223/tasks/abc223_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.10.2021 10:51:24 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	if(n>0 && n%100==0){
		cout<<"Yes\n";
	}else cout<<"No";
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
//	parsed : 21-October-2021 10:51:06 IST