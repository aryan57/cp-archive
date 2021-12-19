/*
	group : AtCoder - M-SOLUTIONS Programming Contest 2021(AtCoder Beginner Contest 232)
	name : D - Weak Takahashi.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Weak_Takahashi.cpp
	url : https://atcoder.jp/contests/abc232/tasks/abc232_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 19.12.2021 17:44:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int h,w;
	cin>>h>>w;

	vector< vector<int> > g(h+1,vector <int> (w+1));
	vector< vector<int> > dp(h,vector <int> (w));

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			char x;
			cin>>x;
			if(x=='.')g[i][j]=1;
		}
	}

	int ans=1;
	dp[0][0]=1;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(!g[i][j])continue;
			if(i==0 && j==0)continue;
			if(i==0){
				if(g[i][j-1]==1)
				dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
				else g[i][j]=0;
			}
			else if(j==0){
				if(g[i-1][j])
				dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
				else g[i][j]=0;
			}else{
				if(g[i-1][j])
				dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
				if(g[i][j-1])
				dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
				if(!g[i][j-1] && !g[i-1][j]){
					g[i][j]=0;
				}
			}

			if(!g[i][j+1] && !g[i+1][j])
			ans=max(ans,dp[i][j]);
		}
	}

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
//	parsed : 19-December-2021 17:44:12 IST