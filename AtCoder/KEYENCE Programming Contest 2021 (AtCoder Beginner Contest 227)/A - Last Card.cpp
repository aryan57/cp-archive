/*
	group : AtCoder - KEYENCE Programming Contest 2021 (AtCoder Beginner Contest 227)
	name : A - Last Card.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Last_Card.cpp
	url : https://atcoder.jp/contests/abc227/tasks/abc227_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 13.11.2021 17:31:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k,a;
	cin>>n>>k>>a;
	int x=(a+k-1)%n;

	if(x==0)x=n;

	cout<<x;

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
//	parsed : 13-November-2021 17:30:14 IST