//https://codeforces.com/contest/1471/problem/F

/*
    // tut used...
    credits: @92anurag
    author : Aryan Agarwal, IIT KGP
    created : 06-January-2021 18:56:39 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 3e5;
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

vector< vector<int> > adj(mxn);
vector <bool> vis(mxn);
vector <int> col(mxn);
int cnt,ans;

void dfs(int u){
    vis[u]=true;
    cnt++;

    if(col[u]==0)
    {
        col[u]=1;
        ans++;
        for(int to: adj[u])
            col[to]=2;
    }

    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

void solve_LOL()
{
    int n,m;
    cin>>n>>m;

    F(i,0,n-1)
    {
        adj[i].clear();
        vis[i]=false;
        col[i]=0;
    }

    F(i,0,m-1)
    {
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cnt=ans=0;
    dfs(0);

    if(cnt!=n)
    {
        cout<<"NO\n";
        return;
    }


    cout<<"YES\n";
    cout<<ans;
    cout<<"\n";
    F(i,0,n-1)
    {
        if(col[i]==1)cout<<i+1<<" ";
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