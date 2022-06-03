/**
 *    author:  Aryan Agarwal
 *    created: 08.05.2022 23:09:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 2e18;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<pair<int,int> > > dp(n,vector<pair<int,int> > (2,make_pair(inf,inf)));

	for(int i=0;i<n;i+=2){
		for(int j=0;j<2;j++){
			int cost=0;
			if(s[i]-'0'!=j)cost++;
			if(s[i+1]-'0'!=j)cost++;

			if(i==0){
				dp[i][j]={cost,1};
			}else{
				dp[i][j] = min(
					make_pair(cost+dp[i-2][j].first,dp[i-2][j].second),
					make_pair(cost+dp[i-2][j^1].first,dp[i-2][j^1].second+1)
				);
			}
		}
	}

	pair <int,int> ans=min(dp[n-2][0],dp[n-2][1]);
	cout<<ans.first<<" "<<ans.second<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}