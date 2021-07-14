//https://codeforces.com/contest/1468/problem/J

/*
    // sol used..
    author : Aryan Agarwal, IIT KGP
    created : 26-December-2020 02:38:01 IST
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

struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

struct Edge
{
    int u,v,w;
};

bool comp(Edge a,Edge b)
{
    return a.w<b.w;
}

int cnt=0;

void dfs(int u,vector< vector<int> >  &adj ,vector <bool> &vis)
{
    vis[u]=true;
    cnt++;
    for(int to: adj[u])
    {
        if(!vis[to])dfs(to,adj,vis);
    }
}

void solve_LOL()
{

    int n,m,k;
    cin>>n>>m>>k;

    vector< vector<int> > adj(n);
    vector <Edge> e(m); 
    F(i,0,m-1)
    {
        Edge x;
        cin>>x.u>>x.v>>x.w;
        x.u--;
        x.v--;
        e[i]=x;
        if(x.w>k)continue;
        adj[x.u].push_back(x.v);
        adj[x.v].push_back(x.u);
    }

    vector <bool> vis(n,false); 
    cnt=0;
    dfs(0,adj,vis);

    if(cnt==n)
    {
        int ans=INF;
        F(i,0,m-1)
            ans=min(ans,abs(e[i].w-k));

        cout<<ans;
        cout<<"\n";
        return;
    }

    F(i,0,m-1)
    {
        e[i].w=max(0ll,e[i].w-k);
    }

    sort(all(e),comp);

    int cost=0;
    dsu d(n);

    for(Edge edge:e)
    {
        if(!d.same(edge.u,edge.v))
        {
            cost+=edge.w;
            d.merge(edge.u,edge.v);
        }
    }

    cout<<cost;
    cout<<"\n";

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
        solve_LOL();
    }
    return 0;
}