//https://codeforces.com/contest/1453/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 04-December-2020 19:35:33 IST
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

    

    int a[n];
    vector <int> vec(n-1);
    int mn=INF;
    int mx=-INF;
    F(i,0,n-1)
    {
        cin>>a[i];
        if(i)mn=min(mn,a[i]);
        if(i)mx=max(mx,a[i]);
        if(i)vec[i-1]=abs(a[i]-a[i-1]);
        
    }

    // int z=(mn+mx)/2;
    // dbg(z);

    int sum=0;
    F(i,0,n-2)
    {
        sum+=vec[i];
    }

    int ans=min(sum-vec[0],sum-vec[n-2]);
    

    F(i,1,n-2)
    {
        int z=sum-vec[i]-vec[i-1];
        z+=abs(a[i-1]-a[i+1]);
        ans=min(ans,z);
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