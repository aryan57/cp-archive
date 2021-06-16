/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/Documents/cp/c2.cpp
	url : /home/aryan/Documents/cp/c2.cpp
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxdif=1e4+10;

signed main()
{
    int n;
    cin>>n;
    vector <int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(a[i]>b[i])swap(a[i],b[i]);
    }

    int dp[n+1][mxdif]={};
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int pre=0;
        for(int j=0;j<=a[i]-1;j++)pre+=dp[i-1][j];

        for(int j=a[i];j<=b[i];j++)
        {
            dp[i][j]=pre;
            pre+=dp[i-1][j];
        }
    }

    int ans=0;
    for(int j=a[n];j<=b[n];j++)ans+=dp[n][j];

    cout<<ans;

    return 0;
}