//https://codeforces.com/contest/1494/problem/E

/*
    // credits: @Um_nik
    author : Aryan Agarwal, IIT KGP
    created : 03-March-2021 14:41:16 IST
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
    int n,m;
    cin>>n>>m;

    set<pair <pair <int,int> ,char> > s;
    int csame=0;
    int cs=0;

    while (m--)
    {
        char c;
        cin>>c;

        if(c=='+')
        {
            int a,b;
            cin>>a>>b;
            cin>>c;

            s.insert({{a,b},c});

            bool ok = false;
            bool oksame = false;

            F(i,0,25)
            {
                if(s.find({{b,a},'a'+i})!=s.end())
                {
                    ok=true;
                    if('a'+i==c)oksame=true;
                }
            }

            if(ok)
            {
                cs++;
            }
            if(oksame)
            {
                csame++;
            }


        }
        else if(c=='-')
        {
            int a,b;
            cin>>a>>b;

            F(i,0,25)
            {
                if(s.find({{b,a},'a'+i})!=s.end() && s.find({{a,b},'a'+i})!=s.end())
                {
                    csame--;
                }
                if(s.find({{b,a},'a'+i})!=s.end())
                {
                    cs--;
                }
            }

            F(i,0,25)
            {
                if(s.find({{a,b},'a'+i})!=s.end())
                {
                    s.erase({{a,b},'a'+i});
                }
            }


        }
        else
        {
            int k;
            cin>>k;

            if(csame>0)
            {
                cout<<"YES\n";
                continue;
            }
            if(cs>0 && k%2)
            {
                cout<<"YES\n";
                continue;
            }
            cout<<"NO\n";
        }
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