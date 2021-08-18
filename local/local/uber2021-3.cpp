/*
	group : local
	name : uber2021-3.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/uber2021-3.cpp
	url : /home/aryan/Desktop/cp-workspace/uber2021-3.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 31.07.2021 23:36:16 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool is_compact(int x,int y,int n)
{
    while(n)
    {
        if(n%10!=x && n%10!=y)
        {
            return false;
        }
        n/=10;
    }
    return true;
}

void solve()
{
    int M=1e9+7;
    int x,y,n;
    cin>>x>>y>>n;
    vector<vector<int>> dp(n+1,vector<int>(9*n+1));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int d=(i==n?1:0);d<=9;d++)
        {
            for(int j=d;j<=9*n;j++)
            {
                dp[i][j]+=dp[i-1][j-d];
                dp[i][j]%=M;
            }
        }
    }

    int ans=0;
    for(int j=1;j<=9*n;j++)
    {
        if(is_compact(x,y,j))
        {
            ans+=dp[n][j];
            ans%=M;
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