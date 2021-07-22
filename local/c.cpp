/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Documents/cp/c.cpp
	url : /home/aryan/Documents/cp/c.cpp
*/
/*
    author : aryan57
    created : 22-July-2021 15:29:50 IST
*/
#include <bits/stdc++.h>
using namespace std;

#define F(i, a, b) for (int i = a; i <= b; i++)
#define int long long

int sumd(int n)
{
    int ans=0;

    while(n)
    {
        ans+=n%10;
        n/=10;
    }

    return ans;
}

void solve()
{
    const int32_t M = 1000000007;
    int n;
    cin>>n;
    vector <int> s(n+1);
    F(i,1,n)cin>>s[i];

    int dp[1001][1001]={};
    dp[0][0]=1;
    int ans=0;
    F(i,1,n)
    {
        F(j,1,1000)
        {
            if(sumd(j)!=s[i])continue;
            
            // we can use prefix sum to calculate dp[i][j] in O(1), that way time-complexity will be O(N^2)
            F(k,0,j-1)
            {
                dp[i][j]+=dp[i-1][k];
                dp[i][j]%=M;
            }

            if(i==n)
            {
                ans+=dp[i][j];
                ans%=M;

            }
        }
    }

    cout<<ans;cout<<"\n";
}

signed main()
{
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        solve();
    }
    return 0;
}