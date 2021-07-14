/*
    // sol used...
    author : Aryan Agarwal, IIT KGP
    created : 22-December-2020 13:58:47 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 5e18;
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

void solve_LOG()
{
    int x0,y0,ax,ay,bx,by;

    cin>>x0>>y0>>ax>>ay>>bx>>by;


    int x,y,t;
    cin>>x>>y>>t;
    vector<pair <int,int> >s;
    s.pb({x0,y0});

    while(true)
    {
        if((INF-bx)/ax<s.back().X)break;
        if((INF-by)/ay<s.back().Y)break;
        
        s.pb({s.back().X*ax+bx,s.back().Y*ay+by});

    }

    int ans=0;
    
    for(int l=0;l<sz(s);l++)
    {
        for(int r=l;r<sz(s);r++)
        {
            int lef=abs(x-s[l].X)+abs(y-s[l].Y);
            
            int rig=abs(x-s[r].X)+abs(y-s[r].Y);
            
            int tot=abs(s[l].X-s[r].X)+abs(s[l].Y-s[r].Y);

            if(tot<=t-lef || tot<=t-rig)
            {
                ans=max(ans,r-l+1);
                // dbg(l,r,lef,rig,tot);
            }
        }
    }

    cout<<ans;
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}