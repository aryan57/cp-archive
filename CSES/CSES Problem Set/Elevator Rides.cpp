/*
	group : CSES - CSES Problem Set
	name : Elevator Rides.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Elevator_Rides.cpp
	url : https://cses.fi/problemset/task/1653
*/
/**
 *    author:  Aryan Agarwal
 *    created: 19.10.2021 22:01:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

// https://cses.fi/book/book.pdf pg = 104

void solve()
{
	int n,x;
	cin>>n>>x;
	vector<int> w(n);
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	int pw = (1<<n);
	vector<pair<int,int>> dp(pw,{n+1,0});
	dp[0] = {1,0};

	for(int mask=1;mask<pw;mask++){
		for(int bit=0;bit<n;bit++){
			if((mask>>bit)&1){
				pair<int,int> option = dp[mask^(1<<bit)];
				if(option.second+w[bit]<=x){
					option.second+=w[bit];
				}else{
					option.first++;
					option.second=w[bit];
				}
				dp[mask]=min(dp[mask],option);
			}
		}
	}

	cout<<dp[pw-1].first<<"\n";
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
//	parsed : 19-October-2021 22:01:28 IST