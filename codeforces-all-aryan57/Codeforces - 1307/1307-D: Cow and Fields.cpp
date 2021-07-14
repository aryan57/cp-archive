//https://codeforces.com/contest/1307/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 24-December-2020 14:33:43 IST
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

bool comp(pair <int,int> a,pair <int,int> b)
{
    return a.Y-a.X<b.Y-b.X;
}

void solve_LOG()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector <int> a(k);
    F(i,0,k-1){cin>>a[i];--a[i];}

    vector <int> adj[n];

    F(i,0,m-1)
    {
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<int> q;
    vector<bool> visited(n);
    vector<int> distance_s(n),distance_t(n);
    
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
                distance_s[child_node] = distance_s[parent_node] + 1;
            }
        }
    }


    fill(all(visited),false);
    q.push(n-1);
    visited[n-1] = true;
    
    while (!q.empty()) {
    
        int parent_node = q.front();
        q.pop();
    
        for (int child_node : adj[parent_node]) {
    
            if (!visited[child_node])
            {
                visited[child_node] = true;
                q.push(child_node);
                distance_t[child_node] = distance_t[parent_node] + 1;
            }
        }
    }


    vector<pair<int,int> > v(k);

    F(i,0,k-1)
    {
        v[i]={distance_s[a[i]],distance_t[a[i]]};
    }

    sort(all(v),comp);
    int ans=-INF;

    int mx=v[0].Y;

    F(i,1,k-1)
    {
        ans=max(ans,v[i].X+mx+1);
        // dbg(ans,mx);
        mx=max(mx,v[i].Y);

    }
    
    int L=distance_s[n-1];
    ans=min(ans,L);
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