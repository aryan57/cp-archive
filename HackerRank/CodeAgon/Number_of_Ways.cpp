/**
 *    author:  Aryan Agarwal
 *    created: 01.07.2022 12:11:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string a,b,c;
	cin>>a>>b>>c;

	int n=a.size();
	int m=b.size();
	int o=c.size();

	int dp[n+1][m+1][o+1][3]={};
	int M = 1e9 + 7;

	// dp[0][0][0]=1;
	
	for(int i=0;i<=n;i++){
		
		for(int j=0;j<=m;j++){
			
			for(int k=0;k<=o;k++){
				if(k==0){
					dp[i][j][k][2]=1;
					continue;
				}

				if(i && a[i-1]==c[k-1])dp[i][j][k][0] = dp[i-1][j][k-1][0]+dp[i-1][j][k-1][1]+dp[i-1][j][k-1][2];
				if(j && b[j-1]==c[k-1])dp[i][j][k][1] = dp[i][j-1][k-1][0]+dp[i][j-1][k-1][1]+dp[i][j-1][k-1][2];

				if(!i && !j)dp[i][j][k][2] = 0;
				if(i && !j)dp[i][j][k][2] = dp[i-1][j][k][0]+dp[i-1][j][k][2];
				if(!i && j)dp[i][j][k][2] = dp[i][j-1][k][1]+dp[i][j-1][k][2];
				if(i && j)dp[i][j][k][2] = dp[i-1][j][k][0]+dp[i][j-1][k][1]+dp[i-1][j-1][k][2];

				dp[i][j][k][0]%=M;
				dp[i][j][k][1]%=M;
				dp[i][j][k][2]%=M;

				cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k][0]<<" "<<dp[i][j][k][1]<<" "<<dp[i][j][k][2]<<"\n";
			}
		}
	}

	int ans=0;
	ans+=dp[n][m][o][0];
	ans+=dp[n][m][o][1];
	ans+=dp[n][m][o][2];

	cout<<ans<<" | \n";

	ans-=dp[0][m][o][1];
	ans-=dp[0][m][o][2];
	
	ans-=dp[n][0][o][0];
	ans-=dp[n][0][o][2];
	
	ans%=M;
	ans+=M;
	ans%=M;
	cout<<ans;

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}