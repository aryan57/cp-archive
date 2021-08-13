/*
	group : CodeChef - August Challenge 2021 Division 2 (Unrated)
	name : Fat Hut.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Fat_Hut.cpp
	url : https://www.codechef.com/AUG21B/problems/FATHUT
*/
/**
 *    author:  Aryan Agarwal
 *    created: 11.08.2021 19:48:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct node{
	int a,c,l,r;
};
static const int INF=2e18;
void solve()
{
	int n;
	cin>>n;

	vector<node> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i].a>>v[i].c>>v[i].l>>v[i].r;
	}

	sort(v.begin()+1,v.end(),
	[] (const node &a,const node &b) {
		return a.c < b.c;
	});

	vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(2,{INF,INF}));
	dp[0][0]={0,0};
	dp[0][1]={0,0};

	for(int i=1;i<=n;i++){
		dp[i][0].first=v[i].a;
		if(v[i].a > dp[i-1][0].first){
			dp[i][0].second=min(dp[i][0].second,dp[i-1][0].second);
		}
		if(v[i].a > dp[i-1][1].first){
			dp[i][0].second=min(dp[i][0].second,dp[i-1][1].second);
		}

		int x;

		x=v[i].l;
		x=max(x,dp[i-1][0].first);
		// if(x==v[i].a)x++;

		if(x<=v[i].r){
			// {x,dp[i-1][0].second+1}
			dp[i][1]={x,dp[i-1][0].second+1};
		}


		x=v[i].l;
		x=max(x,dp[i-1][1].first);
		// if(x==v[i].a)x++;

		if(x<=v[i].r){
			// {x,dp[i-1][1].second+1}
			// cout<<i<<" "<<dp[i][1].first<<" "<<dp[i][1].second<<"*\n";
			if(dp[i-1][1].second+1<dp[i][1].second){
				dp[i][1]={x,dp[i-1][1].second+1};
			}
			else if(dp[i-1][1].second+1 == dp[i][1].second){
				dp[i][1].first=min(dp[i][1].first,x);
			}
		}

		// cout<<i<<" "<<dp[i][1].first<<" "<<dp[i][1].second<<"^\n";
	}

	int ans=min(dp[n][0].second,dp[n][1].second);
	if(ans>=INF)ans=-1;
	cout<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 11-August-2021 19:48:30 IST