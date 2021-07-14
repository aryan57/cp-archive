//https://codeforces.com/contest/1133/problem/E

/*
    // sol used...
    author : Aryan Agarwal, IIT KGP
    created : 04-January-2021 18:20:51 IST
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

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void solve_LOG()
{
    int n,k;
    cin>>n>>k;

    int a[n];

    F(i,0,n-1)cin>>a[i];

    sort(a,a+n);

    int cnt[n]={};

    F(i,0,n-1)
    {
        while (i+cnt[i]<n && a[i+cnt[i]]-a[i]<=5) 
        {
            cnt[i]++;
        }
        
    }

    int dp[n+1][k+1]={};

    F(i,0,n-1)
    {
        F(j,0,k)
        {
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);

            if(j+1<=k)
                dp[i+cnt[i]][j+1]=max(dp[i+cnt[i]][j+1],dp[i][j]+cnt[i]);
        }
    }

    cout<<dp[n][k];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
    // cout<<fixed<<setprecision(10);
    int _t=1;
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}