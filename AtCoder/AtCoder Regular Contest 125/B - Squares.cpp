/*
	group : AtCoder - AtCoder Regular Contest 125
	name : B - Squares.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Squares.cpp
	url : https://atcoder.jp/contests/arc125/tasks/arc125_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 18:26:42 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;

void solve()
{
	int n;
	cin>>n;

	int z=sqrt(n);

	int ans=0;

	for(int i=1;i<=z+1;i++){
		
		int zz=n/i-i;
		if(zz>=0)ans+=zz/2+1;
		ans%=M;
	
		
	}

	cout<<ans%M;
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
//	parsed : 22-August-2021 18:20:09 IST