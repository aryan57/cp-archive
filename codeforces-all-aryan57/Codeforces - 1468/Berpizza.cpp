/*
    author : Aryan Agarwal, IIT KGP
    created : 25-December-2020 17:50:57 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 5e5;
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

struct cmp {
    bool operator() (pair <int,int> a,pair <int,int> b) const {
        
        if(a.X!=b.X)return a.X>b.X;
        return a.Y<b.Y;
    }
};

void solve_LOG()
{
    int q;
    cin>>q;

    set<pair <int,int> ,cmp> s;
    queue<pair <int,int> > qu;

    // int cnt[mxn+1]={};

    int op,m;
    int id=0;

    int taken[mxn+1]={};

    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>m;
            id++;
            qu.push({m,id});
            s.insert({m,id});
            // cnt[m]++;
            // dbg(op,m);

            // dbg(cnt[103913]);
        }
        if(op==2)
        {
            while(!qu.empty())
            {
                if(!taken[qu.front().Y])
                {
                    cout<<qu.front().Y;
                    cout<<" ";
                    // cnt[qu.front().X]--;
                    taken[qu.front().Y]=1;
                    qu.pop();
                    break;
                }
                qu.pop();
            }
        }
        if(op==3)
        {
            while(taken[(*s.begin()).Y])s.erase(s.begin());
            
            cout<<(*s.begin()).Y;
            cout<<" ";
            // cnt[(*s.begin()).X]--;
            taken[(*s.begin()).Y]=1;
            s.erase(s.begin());
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
        solve_LOG();
    }
    return 0;
}