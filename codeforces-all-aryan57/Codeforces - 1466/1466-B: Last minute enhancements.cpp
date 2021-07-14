//https://codeforces.com/contest/1466/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 30-December-2020 20:32:06 IST
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

void solve_LOL()
{
    int n;
    cin>>n;

    int cnt[2*n+1]={};
    int x[n+1];

    F(i,1,n)
    {
        cin>>x[i];
        cnt[x[i]]++;
    }

    int mx=2*n+1;
    int ans=0;
    RF(i,2*n,1)
    {
        if(cnt[i]==0)continue;

        if(cnt[i]==1)
        {
            if(i<mx)
            {
                ans++;
                mx=i;
            }
            else if(i==mx)
            {
                ans++;
                mx=i-1;
            }
        }
        else
        {
            if(i==mx)
            {
                ans+=1;
                mx=i-1;
            }
            else if(i<mx)
            {
                ans+=2;
                mx=i-1;
            }
            // else
            // {
            //     ans+=1;
            //     mx=i-1;
            // }
            
        }
        // dbg(i,ans);
        
    }

    cout<<ans;
    cout<<"\n";
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
    // cout<<fixed<<setprecision(10);
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}