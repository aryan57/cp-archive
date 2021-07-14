/*
    author : Aryan Agarwal, IIT KGP
    created : 18-December-2020 22:59:02 IST
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

void solve()
{
    int a,b;
    cin>>a>>b;

    string s;
    cin>>s;

    int n=sz(s);

    int x[n+1],y[n+1];
    x[0]=y[0]=0;

    if(0==a && 0==b)
    {
        cout<<"Yes";
        return;
    }

    F(i,0,n-1)
    {
        x[i+1]=x[i];
        y[i+1]=y[i];

        if(s[i]=='L')x[i+1]--;
        if(s[i]=='R')x[i+1]++;
        if(s[i]=='U')y[i+1]++;
        if(s[i]=='D')y[i+1]--;

        if(x[i+1]==a && y[i+1]==b)
        {
            cout<<"Yes";
            return;
        }
    }

    int p=x[n],q=y[n];

    F(i,1,n)
    {
        bool ok = false;
        if(p && q)
        {
            if((a-x[i])%p==0 && (b-y[i])%q==0 && ((a-x[i])/p == (b-y[i])/q) && (a-x[i])/p>=0)
            {
                ok=true;
            }
        }
        if(p && !q)
        {
            if((a-x[i])%p==0 && (a-x[i])/p>=0 && y[i]==b)
            {
                ok=true;
            }
        }
        if(!p && q)
        {
            if((b-y[i])%q==0 && (b-y[i])/q>=0 && x[i]==a)
            {
                ok=true;
            }
        }

        if(ok)
        {
            cout<<"Yes";
            return;
        }
    }

    cout<<"No";


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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}