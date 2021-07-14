//https://codeforces.com/contest/1416/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 04-December-2020 17:39:41 IST
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
    int n;
    cin>>n;
 
    int a[n+1],sum=0;
 
    F(i,1,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n)
    {
        cout<<"-1\n";
        return;
    }
 
    vector <tuple<int,int,int> > ans;
 
    F(i,2,n)
    {
        if(a[i]%i)
        {
            ans.pb({1,i,i-a[i]%i});
            ans.pb({i,1,1+a[i]/i});
        }
        else
        {
            ans.pb({i,1,a[i]/i});
        }
        
    }
    F(i,2,n)
    {
        ans.pb({1,i,sum/n});
    }
 
    cout<<sz(ans);cout<<"\n";
    for(auto z : ans)
    {
        int p,q,r;
        tie(p,q,r)=z;
        cout<<p<<" "<<q<<" "<<r;cout<<"\n";
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
    sieve();
#endif
#ifdef ARYAN_FACT
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