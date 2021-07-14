//https://codeforces.com/contest/1420/problem/D

/*
    // solution and tut used
    credits : @Black.n.White
    author : Aryan Agarwal, IIT KGP
    created : 10-December-2020 22:00:16 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
// const int32_t M = 1000000007; /*more than (10)^9*/ /*7 + 1e9*/
const int32_t M = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
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

#define ARYAN_FACT
const int mxn_fact = 3e5;

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
    int n,k;
    cin>>n>>k;

    vector<pair<int,int> > v(n);

    F(i,0,n-1)
    {
        cin>>v[i].X>>v[i].Y;
    }

    sort(all(v));

    multiset <int> s;

    int ans=0;

    F(i,0,n-1)
    {
        while(!s.empty() && *s.begin()<v[i].X)s.erase(s.begin());

        int r=sz(s);
        // rC(k-1);
        if(r>=k-1)
        {
            int z=1;
            z*=fact[r];
            z%=M;
            z*=invfact[k-1];
            z%=M;
            z*=invfact[r-k+1];
            z%=M;

            ans+=z;
            ans%=M;
        }

        s.insert(v[i].Y);

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