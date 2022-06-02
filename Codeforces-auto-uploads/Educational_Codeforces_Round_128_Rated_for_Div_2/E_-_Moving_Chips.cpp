/**
 *    author:  Aryan Agarwal
 *    created: 14.05.2022 07:24:41 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 2e18;
void solve()
{
	int n;
	cin>>n;
	vector<string> v(2);
	cin>>v[0];
	cin>>v[1];

	int l=n;
	int r=-1;

	for(int i=0;i<n;i++){
		if(v[0][i]=='*' || v[1][i]=='*')
		l=min(l,i),r=max(r,i);
	}

	vector<vector<int>> dp(2,vector<int>(n,inf));

	for(int j : {0,1}){
		if(v[j][l]=='*' && v[1^j][l]!='*')dp[j][l]=0;
		else dp[j][l]=1;
	}

	for(int i=l+1;i<=r;i++){
		for(int j : {0,1}){
			for(int k : {0,1}){
				if(j==k && v[j^1][i]!='*')dp[j][i]=min(dp[j][i],dp[k][i-1]+1);
				else dp[j][i]=min(dp[j][i],dp[k][i-1]+2);
			}
		}
	}

	cout<<min(dp[0][r],dp[1][r])<<"\n";
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