/*
	group : CodeChef - December Challenge 2021 Division 1 (Unrated)
	name : Rock Paper Scissors.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Rock_Paper_Scissors.cpp
	url : https://www.codechef.com/DEC21A/problems/ROPASCI
*/
/**
 *    author:  Aryan Agarwal
 *    created: 04.12.2021 21:21:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int dp[n][3];
	dp[n-1][0]=0;
	dp[n-1][1]=1;
	dp[n-1][2]=2;

	for(int i=n-2;i>=0;i--){
		if(s[i+1]=='R'){
			dp[i][0]=dp[i+1][0]; // R R - R
			dp[i][1]=dp[i+1][1]; // P R - P
			dp[i][2]=dp[i+1][0]; // S R - R
		}
		if(s[i+1]=='P'){
			dp[i][0]=dp[i+1][1]; // R P - P
			dp[i][1]=dp[i+1][1]; // P P - P
			dp[i][2]=dp[i+1][2]; // S P - S
		}
		if(s[i+1]=='S'){
			dp[i][0]=dp[i+1][0]; // R S - R
			dp[i][1]=dp[i+1][2]; // P S - S
			dp[i][2]=dp[i+1][2]; // S S - S
		}
	}
	for(int i=0;i<n;i++){
		int id=0;
		if(s[i]=='P')id=1;
		if(s[i]=='S')id=2;
		if(dp[i][id]==0)cout<<"R";
		if(dp[i][id]==1)cout<<"P";
		if(dp[i][id]==2)cout<<"S";
	}
	cout<<"\n";
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
//	parsed : 04-December-2021 21:21:46 IST