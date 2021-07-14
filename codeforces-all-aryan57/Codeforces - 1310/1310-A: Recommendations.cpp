//https://codeforces.com/contest/1310/problem/A

/*
    // tut used....
    author : Aryan Agarwal, IIT KGP
    created : 22-December-2020 08:53:51 IST
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

    vector<pair<int,int> > v(n);

    F(i,0,n-1)
    {
        cin>>v[i].X;
    }
    F(i,0,n-1)
    {
        cin>>v[i].Y;
    }


    sort(all(v));

    int mn=v[0].X;

    multiset<int> t;

    int ind=0;
    int ans=0;
    int sum=0;
    while(ind<n)
    {
        while(ind<n && v[ind].X==mn)
        {
            t.insert(v[ind].Y);
            sum+=v[ind].Y;
            ind++;
        }

        while(!t.empty())
        {
            auto it=t.end();
            it--;
            sum-=(*it);
            ans+=sum;
            t.erase(it);

            mn++;

            while(ind<n && v[ind].X==mn)
            {
                t.insert(v[ind].Y);
                sum+=v[ind].Y;
                ind++;
            }
        }

        
        
        if(ind==n)break;
        mn=v[ind].X;
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
        solve();
    }
    return 0;
}