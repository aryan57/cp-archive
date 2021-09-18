/*
	group : AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest 219）
	name : D - Strange Lunchbox.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Strange_Lunchbox.cpp
	url : https://atcoder.jp/contests/abc219/tasks/abc219_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.09.2021 17:43:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;

void solve()
{
	int n;
	cin>>n;

	int x,y;
	cin>>x>>y;

	vector< pair <int,int>  > v(n+1);

	for(int i=1;i<=n;i++)
	{
		cin>>v[i].first>>v[i].second;
	}

	vector< vector<vector <int> > > dp(n+1,vector< vector<int> > (301,vector <int> (301,inf)));
	vector< vector<int> > mn(301,vector <int> (301,inf));
	dp[0][0][0]=0;
	mn[0][0]=0;

	int ans=inf;

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=300;j++)
		{
			for(int k=0;k<=300;k++)
			{
				int jj=min(300,j+v[i].first);
				int kk=min(300,k+v[i].second);
				dp[i][jj][kk] = min(dp[i][jj][kk],mn[j][k]+1);
			}
		}
		for(int j=0;j<=300;j++)
		{
			for(int k=0;k<=300;k++)
			{
				mn[j][k]=min(mn[j][k],dp[i][j][k]);

				if(j>=x && k>=y){
					ans=min(ans,mn[j][k]);
				}
			}
		}
	}

	if(ans==inf)ans=-1;

	cout<<ans;
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
//	parsed : 18-September-2021 17:40:02 IST