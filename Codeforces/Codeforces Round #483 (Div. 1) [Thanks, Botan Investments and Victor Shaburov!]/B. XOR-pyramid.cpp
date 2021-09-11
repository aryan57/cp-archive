/*
	group : Codeforces - Codeforces Round #483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]
	name : B. XOR-pyramid.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_XOR_pyramid.cpp
	url : https://codeforces.com/contest/983/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 11.09.2021 15:29:05 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int dp[n+1][n+1]={};

	vector<int> v(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}

	for(int i=n;i>=1;i--)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j){
				dp[i][j]=v[i];
				continue;
			}

			dp[i][j]=dp[i][j-1]^dp[i+1][j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j){
				dp[i][j]=v[i];
				continue;
			}

			dp[i][j]=max({dp[i][j],dp[i][j-1],dp[i+1][j]});
		}
	}

	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<dp[l][r]<<"\n";
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
//	parsed : 11-September-2021 15:18:29 IST