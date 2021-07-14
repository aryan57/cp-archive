//https://codeforces.com/contest/1446/problem/C

/*
    // sol and tut used
    author : Aryan Agarwal, IIT KGP
    created : 11-December-2020 19:38:50 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 2e5;
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



int fun(int bit,vector <int> s)
{
    int x=sz(s);
    if(bit==-1)
    {
        return x;
    }
    
    vector <int> s0,s1;

    F(i,0,x-1)
    {
        if((s[i]>>bit)&1)s1.pb(s[i]);
        else s0.pb(s[i]);
    }

    if(s0.empty())return fun(bit-1,s1);
    if(s1.empty())return fun(bit-1,s0);

    return 1+max(fun(bit-1,s1),fun(bit-1,s0));

}

void solve()
{
    int n;
    cin>>n;
    vector <int> a(n);

    F(i,0,n-1)
    {
        cin>>a[i];
    }

    cout<<n-fun(30,a);
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