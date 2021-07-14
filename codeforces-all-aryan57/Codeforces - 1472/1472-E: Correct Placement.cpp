//https://codeforces.com/contest/1472/problem/E

/*
    author : Aryan Agarwal, IIT KGP
    created : 04-January-2021 20:56:46 IST
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

void solve_LOL()
{
    int n;
    cin>>n;

    vector<pair<pair <int,int> ,int> > v(n);

    F(i,0,n-1)
    {
        int l,r;
        cin>>l>>r;
        if(r<l)swap(l,r);

        v[i]={{l,r},i};
    }

    sort(all(v));

    int ans[n];

    multiset<pair <int,int> > s;

    F(i,0,n-1)
    {
        int l=v[i].X.X;
        int r=v[i].X.Y;

        vector <pair <int,int> > vec;

        while(i<n && v[i].X.X==l)
        {
            
            if(!s.empty() && (*s.begin()).X<v[i].X.Y)
            {
                ans[v[i].Y]=(*s.begin()).Y;
            }
            else
            {
                ans[v[i].Y]=-1;
            }

            vec.pb({v[i].X.Y,v[i].Y+1});
            

            i++;
        }

        i--;

        for(pair <int,int> p:vec)
        {
            s.insert(p);
        }
        
    }

    F(i,0,n-1)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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