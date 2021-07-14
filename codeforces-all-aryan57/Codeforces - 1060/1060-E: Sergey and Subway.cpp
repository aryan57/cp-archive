//https://codeforces.com/contest/1060/problem/E

/*
    author : aryan57
    created : 09-June-2021 04:22:01 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 2e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);
vector <int> adj[mxn+1];
vector <int> sub(mxn+1);
int ans=0;
int o=0;
int t=0;
int n;
void dfs(int u,int odd,int tot,int p=-1)
{
    ans+=(tot-odd)/2+odd;
    for(int to : adj[u])
    {
        if(to!=p)
        {
            dfs(to,n-odd,tot-sub[to]+(n-sub[to]),u);
        }
    }
}

int dfs2(int u,int h=0,int p=-1)
{
    sub[u]++;
    if(h%2)o++;
    t+=h;
    for(int to:adj[u])
    {
        if(to!=p)
        {
            sub[u]+=dfs2(to,h+1,u);
        }
    }

    return sub[u];
}

void solve_LOG()
{
    
    cin>>n;

    F(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs2(1);
    
    dfs(1,o,t);

    cout<<ans/2;
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
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
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
//	parsed : 09-June-2021 04:21:47 IST