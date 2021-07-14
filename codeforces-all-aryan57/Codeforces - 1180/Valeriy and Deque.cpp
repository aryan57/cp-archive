/*
    author : Aryan Agarwal, IIT KGP
    created : 17-December-2020 14:43:17 IST
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
    int n,q;
    cin>>n>>q;

    deque <int> d;
    int mx=-INF;

    F(i,0,n-1)
    {
        int x;
        cin>>x;
        mx=max(mx,x);
        d.push_back(x);
    }

    vector<pair<int,int> > ans(n+1);
    int ind=1;

    while(d.front()!=mx)
    {
        int p=d.at(0),q=d.at(1);

        ans[ind++]={p,q};

        d.pop_front();
        d.pop_front();

        if(p>q)
        {
            d.push_front(p);
            d.push_back(q);
        }
        else
        {
            d.push_front(q);
            d.push_back(p);
        }
        
    }

    int m;
    while (q--)
    {
        cin>>m;
        if(m<ind)
        {
            cout<<ans[m].X<<" "<<ans[m].Y<<"\n";
        }
        else
        {
            cout<<mx<<" "<<(d.at((m-ind)%(n-1)+1))<<"\n";
        }
        
    }
    
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