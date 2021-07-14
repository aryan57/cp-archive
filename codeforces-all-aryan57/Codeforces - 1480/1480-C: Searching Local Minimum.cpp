//https://codeforces.com/contest/1480/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 12-February-2021 16:56:26 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than 1e9 */ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than 1e9 */   /*1 + 7*17*(1<<23) */
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

void solve_LOG()
{
    int n;
    cin>>n;


    int a[n+2]={};
    a[0]=a[n+1]=INF;

    int l=1;
    int r=n;
    while(l<=r)
    {
        int m=(l+r)/2;

        if(!a[m])
        {
            cout<<"? "<<m<<endl;
            fflush(stdout);
            cin>>a[m];
        }

        if(m+1<=n && !a[m+1])
        {
            cout<<"? "<<m+1<<endl;
            fflush(stdout);
            cin>>a[m+1];
        }
        if( m-1>=1 && !a[m-1])
        {
            cout<<"? "<<m-1<<endl;
            fflush(stdout);
            cin>>a[m-1];
        }
        if(a[m]<min(a[m+1],a[m-1]))
        {
            cout<<"! "<<m<<endl;
            fflush(stdout);
            return;
        }
        if(a[m-1]<a[m] && a[m]<a[m+1])
        {
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
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
        solve_LOG();
    }
    return 0;
}