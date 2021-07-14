//https://codeforces.com/contest/1478/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 29-January-2021 11:48:19 IST
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
    int n,d;
    cin>>n>>d;

    vector< set<int> > v(100);
    set<int> s;

    int to=(d-1)*10+d;
    int x=d;
    while(x<=to){
        s.insert(x%d);
        for(int ss : s)v[x].insert(ss);
        x+=10;
    }

    to=(d)*10+9;
    x=d*10;
    // s.clear();
    while(x<=to){
        s.insert(x%d);
        for(int ss : s)v[x].insert(ss);
        x+=1;
    }

    // for (int i=d;i<=10*(d-1)+d;i+=10)
    // {
    //     cout<<i<<" | ";
    //     for(int ss : v[i])cout<<ss<<" ";
    //     cout<<"\n";
    //     // dbg(i);
    // }
    // for (int i=d*10;i<=10*(d)+9;i+=1)
    // {
    //     cout<<i<<" | ";
    //     for(int ss : v[i])cout<<ss<<" ";
    //     cout<<"\n";
    //     // dbg(i);
    // }

    // sort(all(v),greater<int> ());

    F(i,0,n-1){
        int num;
        cin>>num;
        // num%=d;

        bool ok = false;

        RF(i,99,0){
            if(i<=num){
                if(v[i].find(num%d)!=v[i].end())ok=true;
            }
        }

        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}