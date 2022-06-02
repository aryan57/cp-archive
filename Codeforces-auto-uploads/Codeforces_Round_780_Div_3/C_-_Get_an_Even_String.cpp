/**
 *    author:  Aryan Agarwal
 *    created: 09.05.2022 10:54:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 2e18;

void solve()
{
	string s;
	cin>>s;

	int n=s.size();

	int dp[n+1][27];
	fill_n(&dp[0][0],(n+1)*27,inf);
	dp[0][26]=0;
	
	for(int i=1;i<=n;i++){

		for(int j=0;j<=26;j++){
			dp[i][j] = dp[i-1][j]+1;
		}
		
		for(int j=0;j<26;j++){
			int add=2;
			if(j==s[i-1]-'a')add=0;
			dp[i][26] = min(dp[i][26],dp[i-1][j]+add);
			// dp[i][s[i-1]-'a'] = min(dp[i][s[i-1]-'a'],dp[i-1][j]+1);
			dp[i][s[i-1]-'a'] = min(dp[i][s[i-1]-'a'],dp[i-1][26]);
		}
	}

	cout<<dp[n][26]<<"\n";
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