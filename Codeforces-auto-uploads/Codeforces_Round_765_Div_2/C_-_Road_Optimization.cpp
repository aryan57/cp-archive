/**
 *    author:  Aryan Agarwal
 *    created: 12.01.2022 18:11:24 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;
void solve()
{
	int n,l,k;
	cin>>n>>l>>k;
	vector <int> d(n),a(n);
	for(int &x : d)cin>>x;
	for(int &x : a)cin>>x;
	d.push_back(l);

	vector< vector<int> > dp(n+1,vector <int> (k+1,INF));
	for(int i=0;i<=k;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int prev=i-1;prev>=0;prev--){
				int tobreak=i-prev-1;
				if(tobreak+j>k)break;
				dp[i][j]=min(dp[i][j],dp[prev][tobreak+j]+(d[i]-d[prev])*a[prev]);
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=k;i++)ans=min(ans,dp[n][i]);
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
//	parsed : 12-January-2022 17:55:57 IST