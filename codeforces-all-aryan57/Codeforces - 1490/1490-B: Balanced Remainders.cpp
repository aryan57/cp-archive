//https://codeforces.com/contest/1490/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 16-February-2021 20:16:03 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than 1e9 */ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than 1e9 */   /*1 + 7*17*(1<<23) */
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

    int a[n];
    int c[3]={};
    F(i,0,n-1)
    {
        cin>>a[i];
        c[a[i]%3]++;
    }

    int k=n/3;

    int ans=0;

    if(c[0]>k)
    {
        ans+=c[0]-k;
        c[1]+=c[0]-k;
        c[0]=k;
    }
    if(c[1]>k)
    {
        ans+=c[1]-k;
        c[2]+=c[1]-k;
        c[1]=k;
    }
    if(c[2]>k)
    {
        ans+=c[2]-k;
        c[0]+=c[2]-k;
        c[2]=k;
    }
    if(c[0]>k)
    {
        ans+=c[0]-k;
        c[1]+=c[0]-k;
        c[0]=k;
    }
    if(c[1]>k)
    {
        ans+=c[1]-k;
        c[2]+=c[1]-k;
        c[1]=k;
    }
    if(c[2]>k)
    {
        ans+=c[2]-k;
        c[0]+=c[2]-k;
        c[2]=k;
    }

    cout<<ans;
    cout<<"\n";
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}