//https://codeforces.com/contest/1492/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 24-February-2021 10:29:23 IST
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
    int a,b,k;
    cin>>a>>b>>k;
    b--;

    string sa="1";
    string sb="1";
    bool ok = false;

    if(k==0)
    {
        sa+=string(b,'1');
        sa+=string(a,'0');
        sb+=string(b,'1');
        sb+=string(a,'0');
        ok = true;
    }
    else if(a>=1 && b>=1 && k<=a+b-1 && k>=1)
    {
        a--;
        b--;
        sa+='1';
        sb+='0';
        k--;
        while(k>0 && a)
        {
            sa+='0',sb+='0',k--,a--;
        }
        while(k>0 && b)
        {
            sa+='1',sb+='1',k--,b--;
        }
        sa+='0';
        sb+='1';
        while(a || b)
        {
            if(a)sa+='0',sb+='0',a--;
            if(b)sa+='1',sb+='1',b--;
        }

        ok = true;
    }

    if(ok)
    {
        cout<<"Yes\n";
        cout<<sa;
        cout<<"\n";
        cout<<sb;
    }
    else
    {
        cout<<"No\n";
    }

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