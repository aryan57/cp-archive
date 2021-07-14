//https://codeforces.com/contest/1467/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 08-January-2021 21:07:22 IST
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
    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    int a1[n1],a2[n2],a3[n3];
    int s1=0,s2=0,s3=0;
    F(i,0,n1-1)
    {
        cin>>a1[i];
        s1+=a1[i];
    }
    F(i,0,n2-1)
    {
        cin>>a2[i];
        s2+=a2[i];
    }
    F(i,0,n3-1)
    {
        cin>>a3[i];
        s3+=a3[i];
    }

    sort(a1,a1+n1);
    sort(a2,a2+n2);
    sort(a3,a3+n3);

    int ans=-INF;
    int tot=s1+s2+s3;
    // dbg(s1,s2,s3,tot,a1[0],a2[0]);
    ans=max(ans,tot-2*(a1[0]+a2[0]));
    // dbg(ans);
    ans=max(ans,tot-2*(a1[0]+a3[0]));
    // dbg(ans);
    ans=max(ans,tot-2*(a3[0]+a2[0]));
    // dbg(ans);

    // if(n1>=2)
    {
        ans=max(ans,s1+s2-s3);
        ans=max(ans,s1-s2+s3);
    }
    // else
    // {
    //     ans=max(ans,s1-s2-s3);
    // }
    
    // if(n2>=2)
    {
        ans=max(ans,s1+s2-s3);
        ans=max(ans,-s1+s2+s3);
    }
    // else
    // {
    //     ans=max(ans,-s1+s2-s3);
    // }
    // if(n3>=2)
    {
        ans=max(ans,s1-s2+s3);
        ans=max(ans,-s1+s2+s3);
    }
    // else
    // {
    //     ans=max(ans,-s1-s2+s3);
    // }


    cout<<ans;

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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}