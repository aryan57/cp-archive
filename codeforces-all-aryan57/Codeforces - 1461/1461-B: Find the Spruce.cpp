//https://codeforces.com/contest/1461/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 11-December-2020 20:18:49 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than (10)^9*/ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(a) cout<<"["<<#a<<" : "<<a<<"]\n"
#define dbg2(a,b) cout<<"["<<#a<<" : "<<a<<"], "<<"["<<#b<<" : "<<b<<"]\n"
#define dbg3(a,b,c) cout<<"["<<#a<<" : "<<a<<"], "<<"["<<#b<<" : "<<b<<"], "<<"["<<#c<<" : "<<c<<"]\n"

void solve()
{
    int n,m;
    cin>>n>>m;

    char a[n][m];
    int le[n][m],ri[n][m];

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            cin>>a[i][j];
        }
    }


    F(i,0,n-1)
    {
        int cur=0;
        F(j,0,m-1)
        {
            if(a[i][j]=='.')cur=0;
            else cur++;
            le[i][j]=cur;
        }
        cur=0;
        RF(j,m-1,0)
        {
            if(a[i][j]=='.')cur=0;
            else cur++;
            ri[i][j]=cur;
        }
    }

    int kk[n][m]={};

    int ans=0;
    F(j,0,m-1){if(a[0][j]=='*'){kk[0][j]=1;ans++;}}

    // dbg(ans);

    F(i,1,n-1)
    {
        F(j,0,m-1)
        {
            if(a[i][j]=='.')continue;

            int k=kk[i-1][j];
            int len=min(le[i][j],ri[i][j]);
            if(len>=k+1)
            {
                kk[i][j]=k+1;
                ans+=k+1;
            }
            else
            {
                kk[i][j]=len;
                ans+=len;
            }
            
        }
    }

    cout<<ans;cout<<"\n";

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
    // defualt mxn_sieve = 1e5
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    // default [L,R] = [1,1e5]
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    // default mxn_fact = 1e5
    fact_init();
#endif
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}