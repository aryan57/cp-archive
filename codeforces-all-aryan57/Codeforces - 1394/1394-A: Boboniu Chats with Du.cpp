//https://codeforces.com/contest/1394/problem/A

/*
    // tut used...
    author : Aryan Agarwal, IIT KGP
    created : 11-December-2020 12:18:14 IST
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
    int n,d,m;
    cin>>n>>d>>m;

    vector <int> a(n);
    vector <int> gre,leq;

    F(i,0,n-1)
    {
        cin>>a[i];
        if(a[i]>m)
        {
            gre.pb(a[i]);
        }
        else
        {
            leq.pb(a[i]);
        }
        
    }

    sort(all(gre),greater <int> ());
    sort(all(leq),greater <int> ());

    // convert them in prefix sums...

    F(i,1,sz(gre)-1)
    {
        gre[i]+=gre[i-1];
    }
    F(i,1,sz(leq)-1)
    {
        leq[i]+=leq[i-1];
    }

    int ans=-INF;

    F(x,0,sz(gre))
    {
        int z=n-(x+(x-1)*d);
        if(x==0)z=n;
        if(z<0)continue;
        if(z>sz(leq))
        {
            if(sz(leq)+d>=z)
            {
                z=sz(leq);
            }
            else
            {
                continue;
            }
            
        }
        // dbg2(x,z);
        int t=0;
        if(x)t+=gre[x-1];
        if(z)t+=leq[z-1];

        ans=max(ans,t);
    }

    cout<<ans;

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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}