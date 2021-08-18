/*
	group : local
	name : uber2021-2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/uber2021-2.cpp
	url : /home/aryan/Desktop/cp-workspace/uber2021-2.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 01.08.2021 00:20:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int M=1e9+7;

    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];

    int dp[n+1][k+1][2]={};
    int ans=0;

    /*
        dp[i][j][0] sum of product of subsets of length 'j' ending at 'i' having odd elements even times
        dp[i][j][1] sum of product of subsets of length 'j' ending at 'i' having odd elements odd times
    */
    
    for(int j=1;j<=k;j++)
    {
        int pre[2]={};
        for(int i=1;i<=n;i++)
        {
            if(j==1){
                dp[i][j][a[i]%2]=a[i];
                continue;
            }
            
            for(int bit : {0,1})
            {
                dp[i][j][bit] += a[i]*pre[(a[i]%2)^bit];
                dp[i][j][bit] %= M;

                pre[bit]+=dp[i][j-1][bit];
                pre[bit]%=M;
            }

            if(j==k){
                ans+=dp[i][j][0];
                ans%=M;
            }
        }
    }

    cout<<ans<<"\n";
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