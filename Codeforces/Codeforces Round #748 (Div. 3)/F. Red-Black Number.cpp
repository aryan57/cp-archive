/*
	group : Codeforces - Codeforces Round #748 (Div. 3)
	name : F. Red-Black Number.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Red_Black_Number.cpp
	url : https://codeforces.com/contest/1593/problem/F
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.10.2021 09:41:04 IST
**/
#include <bits/stdc++.h>
using namespace std;

const int mxn = 64;

bool dp[mxn][mxn][mxn][mxn]={};
pair <bool,int> parent [mxn][mxn][mxn][mxn];

void solve()
{
	int n,a,b;
	cin>>n>>a>>b;

	string x;
	cin>>x;

	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int ra=0;ra<a;ra++)
				for(int rb=0;rb<b;rb++)
					dp[i][j][ra][rb] = false;

	dp[0][0][0][0] = true;

	for(int taken = 0; taken<n; taken++)
		for(int red=0;red<=taken;red++)
			for(int remA=0;remA<a;remA++)
				for(int remB=0;remB<b;remB++){
					if(!dp[taken][red][remA][remB])continue;
					//red
					dp[taken+1][red+1][(remA*10 + (x[taken]-'0'))%a][remB] = true;
					parent[taken+1][red+1][(remA*10 + (x[taken]-'0'))%a][remB] = {true,remA};
					//black
					dp[taken+1][red][remA][(remB*10 + (x[taken]-'0'))%b] = true;
					parent[taken+1][red][remA][(remB*10 + (x[taken]-'0'))%b] = {false,remB};
				}
			
	int bestRed = 0;

	for(int red=1;red<n;red++)
		if(dp[n][red][0][0] && abs(red-(n-red)) < abs(bestRed-(n-bestRed)))bestRed=red;

	if(bestRed==0){
		cout<<"-1\n";
		return;
	}

	int taken=n;
	int remA=0;
	int remB=0;
	int red=bestRed;

	string ans="";

	while (taken>0)
	{
		assert(dp[taken][red][remA][remB]);
		auto way = parent[taken][red][remA][remB];

		if(way.first){
			ans+='R';
			red--;
			remA=way.second;
		}else{
			ans+='B';
			remB=way.second;
		}
		taken--;
	}

	reverse(ans.begin(),ans.end());
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
//	parsed : 16-October-2021 09:40:57 IST