//https://codeforces.com/contest/1468/problem/F

/*
    author : Aryan Agarwal, IIT KGP
    created : 25-December-2020 18:44:02 IST
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

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve_LOL()
{
    int n;
    cin>>n;

    map<pair <int,int> ,int> mp;
    // map<pair <int,int> ,int> mpn;
    int cnt[2][2]={};

    int x1,y1,x2,y2;

    F(i,0,n-1)
    {
        cin>>x1>>y1>>x2>>y2;
        int a=y2-y1;
        int b=x2-x1;
        int gg=abs(gcd(a,b));
        a/=gg;
        b/=gg;
        // dbg(a,b);
        if(a*b)mp[{a,b}]++;
        if(a*b==0)
        {
            if(a>0)
            {
                cnt[0][0]++;
            }
            if(a<0)
            {
                cnt[0][1]++;
            }
            if(b>0)
            {
                cnt[1][0]++;
            }
            if(b<0)
            {
                cnt[1][1]++;
            }
        }
    }

    // dbg(cnt[0][0],cnt[0][1]);


    int ans=0;
    ans+=cnt[0][0]*cnt[0][1];
    ans+=cnt[1][0]*cnt[1][1];
    int k=0;
    for(auto x:mp)
    {
        pair <int,int> p=x.X;
        int c1=x.Y;
        int c2=mp[{-p.X,-p.Y}];

        // dbg(c1,c2,p.X,p.Y);

        k+=c1*c2;
    }

    cout<<ans+k/2;
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
        solve_LOL();
    }
    return 0;
}