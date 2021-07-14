//https://codeforces.com/contest/1463/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 17-December-2020 21:19:08 IST
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

    vector <int> t(n+2);
    vector <int> x(n+2);

    F(i,1,n)
    {
        cin>>t[i]>>x[i];
    }

    // cout<<n<<"**\n";
    // F(i,1,n)
    // {
    //     cout<<t[i]<<" "<<x[i];cout<<"\n";
    // }

    int prep=0,curp=0;
    int curt=0,pret=-1;


    t[n+1]=x[n+1]=INF;


    int ans=0;
    int op=0;

    F(i,1,n+1)
    {
        if(t[i]>=curt)
        {
            int l=curp;
            int r=x[i];
            if(r<l)op=-1;
            else op=1;

            if(abs(r-l)<=t[i+1]-t[i])ans++;

            prep=curp; 
            curp=x[i];
            pret=t[i];
            curt=t[i]+abs(r-l);
        }
        else
        {
            int l=prep+op*(t[i]-pret);
            int r;
            if(t[i+1]<curt)r=prep+op*(t[i+1]-pret);
            else r=curp;

            int l1=min(l,r);
            int r1=max(l,r);
            // if(i==4)
            // {
            //     dbg(l1,r1);
            //     // dbg()
            // }

            if(x[i]>=l1 && x[i]<=r1)ans++;
        }
        
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