//https://codeforces.com/contest/1278/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 19-December-2020 11:14:05 IST
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

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void solve()
{
    int n;
    cin>>n;

    vector <int> a(2*n+1);

    int c2=0,c1=0;

    F(i,1,2*n)
    {
        cin>>a[i];
        if(a[i]==2)c2++;
        else c1++;
    }

    int ans=2*n;
    int d=c2-c1;

    if(d==0)
    {
        cout<<0;
        cout<<"\n";
        return;
    }

    vector <int> rp(n+1,-1);
    vector <int> rn(n+1,-1);


    int s=0;
    rp[0]=n;
    F(i,n+1,2*n)
    {
        if(a[i]==2)s++;
        else s--;
        if(s>=0 && rp[s]==-1)rp[s]=i;
        if(s<0 &&rn[-s]==-1)rn[-s]=i;
    }
    s=0;
    RF(i,n+1,1)
    {
        if(a[i]==2)s++;
        else s--;
        if(i==n+1)s=0;

        int k=d-s;
        if(abs(k)>n)continue;
        if(k>=0 && rp[k]!=-1)ans=min(ans,rp[k]-i+1);
        if(k<0 && rn[-k]!=-1)ans=min(ans,rn[-k]-i+1);
    }

    cout<<ans;
    cout<<"\n";


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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}