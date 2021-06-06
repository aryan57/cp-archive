/*
	group : AtCoder - AtCoder Beginner Contest 204
	name : C - Tour.cpp
	srcPath : /home/aryan/Documents/cp/C_Tour.cpp
	url : https://atcoder.jp/contests/ABC204/tasks/abc204_c
*/
/*
    author : aryan57
    created : 06-June-2021 17:34:47 IST
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

const int mxn = 2000;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

set<pair <int,int> > s;
vector <int> adj[mxn+1];
vector <bool> vis(mxn+1);
void dfs(int st,int u)
{
    vis[u]=true;
    s.insert({st,u});

    for(int to : adj[u])
    {
        if(!vis[to])dfs(st,to);
    }
}

void solve_LOG()
{
    int n,m;
    cin>>n>>m;

    F(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    F(i,1,n)
    {
        F(j,0,n)vis[j]=false;
        dfs(i,i);
    }

    cout<<sz(s);
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
//	parsed : 06-June-2021 17:33:26 IST