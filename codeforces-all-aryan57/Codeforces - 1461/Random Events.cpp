/*
    credits: @yash_daga
    author : Aryan Agarwal, IIT KGP
    created : 11-December-2020 20:46:51 IST
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
    vector <int> a(n);
    vector <int> r(m);
    vector<long double> p(m);

    F(i,0,n-1)
    {
        cin>>a[i];
        --a[i];
    }
    int last=-1,z=-1;
    F(i,0,m-1)
    {
        cin>>r[i];
        cin>>p[i];
        --r[i];
        last=max(last,r[i]);
    }

    // dbg(last);
    F(i,last+1,n-1)
    {
        if(a[i]!=i)
        {
            cout<<fixed<<setprecision(10)<<0.0;
            cout<<"\n";
            return;
        }
    }

    RF(i,last,0)
    {
        if(a[i]!=i)
        {
            z=i;
            break;
        }
    }
    if(z==-1)
    {
        cout<<fixed<<setprecision(10)<<1.0;
        cout<<"\n";
        return;
    }

    long double sq=1.0;

    F(i,0,m-1)
    {
        if(r[i]>=z)
        {
            sq*=(1.0-p[i]);
        }
    }
    
    cout<<fixed<<setprecision(10)<<(long double)(1.0-sq);
    cout<<"\n";
    return;
    

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