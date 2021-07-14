/*
    // tut used...
    author : Aryan Agarwal, IIT KGP
    created : 15-December-2020 01:28:16 IST
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

// https://cp-algorithms.com/graph/lca_binary_lifting.html

// GLOBAL VARIABLES...
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout,height;
vector<vector<int>> up;

void dfs(int v, int p,int cur)
{
    tin[v] = ++timer;
    height[v]=cur++;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v,cur);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    height.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root,0);
}

int pa_len(int u,int v)
{
    int ances=lca(u,v);
    // int ances=0;

    return -height[ances]+height[u]-height[ances]+height[v];
}

void solve()
{
    cin>>n;
    adj.resize(n);
    F(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    preprocess(0);

    int q;
    cin>>q;
    while (q--)
    {
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        --x;--y;--a;--b;

        int p1=pa_len(a,b);
        int p2=pa_len(a,x)+1+pa_len(y,b);
        int p3=pa_len(a,y)+1+pa_len(x,b);
        // dbg(p1,p2,p3);

        int mn=INF;
        if(p1%2==k%2)mn=min(mn,p1);
        if(p2%2==k%2)mn=min(mn,p2);
        if(p3%2==k%2)mn=min(mn,p3);

        if(mn<=k)cout<<"YES\n";
        else
        {
            cout<<"NO\n";
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