/*
	group : Codeforces - Codeforces Round #734 (Div. 3)
	name : E. Fixed Points.cpp
	srcPath : /home/aryan/cp-workspace/E_Fixed_Points.cpp
	url : https://codeforces.com/contest/1551/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.07.2021 00:31:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int tc;
    cin>>tc;
    int INF=2e18;
    while(tc--) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
            a[i]--;
            a[i]-=i;
        }

        int ans=INF;
        int dp[n][n]={};

        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                int t1=0;
                if(i>0 && j>0)t1+=dp[i-1][j-1];

                int t2=0;
                if(i>0)t2+=dp[i-1][j];
                if(a[i]+j==0)t2++;

                dp[i][j]=max(t1,t2);

                if(dp[i][j]>=k)ans=min(ans,j);
            }
        }

        if(ans==INF)ans=-1;

        cout<<ans<<"\n";
    }
    return 0;
}
//	parsed : 25-July-2021 24:31:06 IST