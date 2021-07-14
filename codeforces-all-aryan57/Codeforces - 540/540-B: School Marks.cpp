//https://codeforces.com/contest/540/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 12-December-2020 01:12:46 IST
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
    int n,k,p,x,y;
    cin>>n>>k>>p>>x>>y;

    vector <int> a(k);
    int ss=0;
    F(i,0,k-1)
    {
        cin>>a[i];
        ss+=a[i];
    }

    sort(all(a));

    int cy=n/2+1-(k-(lower_bound(all(a),y)-a.begin()));
    if(cy<0)cy=0;

    // dbg(cy);

    int c1=n-k-cy;
    // if(c1<0)
    // {

    // }
    // dbg(c1);
    // dbg(ss);

    if(c1+ss+cy*y>x || c1<0)
    {
        // dbg(c1+ss+cy*y);
        cout<<"-1\n";
        return;
    }
    
        while(c1--)cout<<1<<" ";
        while(cy--)cout<<y<<" ";
    
    

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