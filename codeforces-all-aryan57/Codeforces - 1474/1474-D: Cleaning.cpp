//https://codeforces.com/contest/1474/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 20-January-2021 17:04:42 IST
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

void solve_LOL()
{
    int n;
    cin>>n;

    vector <int> a(n),b(n);

    F(i,0,n-1)cin>>a[i];
    b[0]=a[0];
    bool ok = true;
    int pos=INF;
    F(i,1,n-1)
    {
        b[i]=a[i]-b[i-1];
        if(b[i]<0)
        {
            if(ok)pos=i;
            ok=false;
        }
    }
    if(b[n-1])ok=false;

    if(ok)
    {
        cout<<"YES\n";
        return;
    }

    vector< vector<int> > mn(2,vector <int> (n+10,INF));

    RF(i,n-1,0)
    {
        if(i%2){
            mn[1][i]=min(mn[1][i],mn[1][i+2]);
            mn[1][i]=min(mn[1][i],b[i]);
            mn[0][i]=mn[0][i+1];
        }else{
            mn[0][i]=min(mn[0][i],mn[0][i+2]);
            mn[0][i]=min(mn[0][i],b[i]);
            mn[1][i]=mn[1][i+1];
        }
    }

    F(i,0,min(n-2,pos))
    {
        int x= a[i] - a[i+1];
        int p= ((n-i-1)%2) ?1:-1;

        if(b[i]-x<0 ||(p*2*x+b[n-1])!=0)
        {
            continue;
        }

        if(mn[(i+1)%2][i+1]+2*x<0)
        {
            continue;
        }

        if(mn[(i+2)%2][i+2]-2*x<0 && mn[(i+2)%2][i+2]!=INF)
        {
            continue;
        }

        cout<<"YES\n";
        return;
    }

    cout<<"NO\n";

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}