/**
 *    author:  Aryan Agarwal
 *    created: 10.07.2022 11:32:06 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> s(n);
	for(int &x : s)cin>>x;
	int m;
	cin>>m;
	vector <int> k(m);
	for(int &x : k)cin>>x;

	int inf = 2e18;

	vector< vector<int> > dp(n,vector <int> (m,inf));

	for(int j=0;j<m;j++){
		if(k[j]==s[n-1])dp[n-1][j]=0;
	}

	for(int i=n-2;i>=0;i--){
		int mn=inf;
		for(int j=0;j<m;j++){
			mn=min(dp[i+1][j]-j,mn);
			if(k[j]==s[i]){
				dp[i][j]=min(dp[i][j],mn+j);
			}
		}
		mn=inf;
		for(int j=m-1;j>=0;j--){
			mn=min(dp[i+1][j]+j,mn);
			if(k[j]==s[i]){
				dp[i][j]=min(dp[i][j],mn-j);
			}
		}
	}

	int ans=inf;
	for(int j=0;j<m;j++){
		ans=min(ans,dp[0][j]);
	}

	cout<<ans;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}