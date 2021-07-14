//https://codeforces.com/contest/1462/problem/E2

/*
    author : Aryan Agarwal, IIT KGP
    created : 15-December-2020 21:12:03 IST
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

#define ARYAN_FACT
const int mxn_fact = 2e5+10;

int fact[mxn_fact + 1];
int invfact[mxn_fact + 1];

void fact_init()
{
    int p = M;

    fact[0] = 1;
    for (int i = 1; i <= mxn_fact; i++)
        fact[i] = (i * fact[i - 1]) % p;

    // res will be binpow(fact[mxn_fact],p-2,p)
    // binpow algo starts....
    int res = 1;
    int x = fact[mxn_fact], y = p - 2;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    // binpow algo ends....

    invfact[mxn_fact] = res;
    for (int i = mxn_fact - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % p;
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector <int> a(n+1);

    vector <int> cnt(n+1,0);
    vector <int> pre(n+1,0);

    F(i,1,n)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    F(i,1,n)
    {
        pre[i]+=pre[i-1]+cnt[i];
        // dbg(pre[i],i);
    }
    // cout<<"**";cout<<"\n";
    int ans=0;
    F(i,1,n)
    {
        // if(cnt[i]==0)continue;
        int z=pre[min(n,i+k)]-pre[i-1];
        // z--;
        if(z<m)continue;

        // dbg(z,i);

        int t=1;
        t*=fact[z];
        t%=M;
        t*=invfact[m];
        t%=M;
        t*=invfact[z-m];
        t%=M;
        int t2=1;
        if(z-cnt[i]<m)t2=0;
        else
        {
            t2*=fact[z-cnt[i]];
            t2%=M;
            t2*=invfact[m];
            t2%=M;
            t2*=invfact[z-cnt[i]-m];
            t2%=M;
        }

        t-=t2;
        t%=M;
        t+=M;
        t%=M;
        
        
        // t*=invfact[2];
        // t%=M;

        ans+=t;
        ans%=M;
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
    // cout<<fixed<<setprecision(10);
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}