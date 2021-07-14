//https://codeforces.com/contest/1472/problem/G

/*
    // stream used...
    credits: @AnandOza
    author : Aryan Agarwal, IIT KGP
    created : 04-January-2021 23:10:24 IST
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
    int n,m;
    cin>>n>>m;

    vector< vector<int> > adj(n);

    F(i,0,m-1)
    {
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
    }

    queue<int> q;
    vector<bool> visited(n);
    vector<int> distance(n);
    
    q.push(0);
    visited[0] = true;
    
    while (!q.empty()) {
    
        int parent_node = q.front();
        q.pop();
    
        for (int child_node : adj[parent_node]) {
    
            if (!visited[child_node])
            {
                visited[child_node] = true;
                q.push(child_node);
                distance[child_node] = distance[parent_node] + 1;
            }
        }
    }

    vector<pair<int,int> > vd(n);

    F(i,0,n-1)
    {
        vd[i]={distance[i],i};
    }


    sort(all(vd),greater<pair <int,int> > ());



    vector <int> ans(n,INF);
    for(pair <int,int> p: vd)
    {
        int u=p.Y;
        ans[u]=distance[u];

        for(int to : adj[u])
        {
            if(distance[to]>distance[u])
            {
                ans[u]=min(ans[u],ans[to]);
            }
            else
            {
                ans[u]=min(ans[u],distance[to]);
            }
            
        }

    }

    for(int x : ans)cout<<x<<" ";
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