/*
    credits : @Black.n.White
    author : Aryan Agarwal, IIT KGP
    created : 11-December-2020 22:50:12 IST
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

set<int> s;

void fun(int l,int r,vector <int> &a,vector <int> &pre)
{
    if(l>r)return;

    int n=sz(a);
    n--;

    s.insert(pre[r]-pre[l-1]);

    int mid=(a[l]+a[r])/2;

    int j=upper_bound(all(a),mid)-a.begin();
    j--;

    if(j<0)return;

    fun(j+1,r,a,pre);
    if(j!=r)fun(l,j,a,pre);
    

}

void solve()
{
    s.clear();
    int n,q;cin>>n>>q;
    vector <int> a(n+1);
    F(i,1,n)
    {
        cin>>a[i];
    }

    sort(all(a));

    vector <int> pre(n+1);
    F(i,1,n)
    {
        pre[i]=pre[i-1]+a[i];
    }

    fun(1,n,a,pre);

    int x;

    while (q--)
    {
        cin>>x;
        if(s.find(x)!=s.end())cout<<"Yes\n";
        else cout<<"No\n";
    }
    
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