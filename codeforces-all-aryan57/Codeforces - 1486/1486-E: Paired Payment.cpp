//https://codeforces.com/contest/1486/problem/E

/*
    // tut used...
    author : Aryan Agarwal, IIT KGP
    created : 19-February-2021 04:14:45 IST
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
    int n,m;
    cin>>n>>m;

    vector <pair <int,int> > adj[n];
    vector< vector<int> > dist(n,vector <int> (51,INF));
    vector< vector<bool> > vis(n,vector <bool> (51,false));

    F(i,0,m-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    priority_queue<pair <int,pair <int,int> > > p;

    p.push({-0,{0,0}});
    dist[0][0]=0;
    // vis[0][0]=1;
    while (!p.empty())
    {
        int node=p.top().Y.X,last_w=p.top().Y.Y;
        p.pop();
        if(vis[node][last_w])
        {
            continue;
        }
        vis[node][last_w]=true;

        for(pair <int,int> pq: adj[node])
        {
            int to=pq.X;
            int weight=pq.Y;

            int new_w=last_w?0:weight;
            int new_d=last_w?(last_w+weight)*(last_w+weight):0;
            new_d+=-dist[node][last_w];
            if(dist[to][new_w]>new_d)
            {
                dist[to][new_w]=new_d;
                p.push({-new_d,{to,new_w}});
            }
        }
        
    }

    F(i,0,n-1)
    {
        if(dist[i][0]==INF)dist[i][0]=-1;
        cout<<dist[i][0]<<" ";
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
        solve_LOL();
    }
    return 0;
}