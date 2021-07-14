//https://codeforces.com/contest/1217/problem/D

/*
    author : aryan57
    created : 08-July-2021 17:14:33 IST
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

const int mxn = 5000;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

vector<int> result(5000,1);
vector<int> color(5000,0);
bool cyclic=false;
vector<pair<int,int> > adj[5000];

void dfs(int u)
{
    color[u]=1;

    for(auto p : adj[u])
    {
        int to=p.X;
        int id=p.Y;

        if(color[to]==0)
        {
            dfs(to);
        }else if(color[to]==1)
        {
            result[id]=2;
            cyclic=true;
        }
    }

    color[u]=2;
}

void solve_LOG()
{
    int n,m;
    cin>>n>>m;

    F(i,0,m-1)
    {
        int u,v;
        cin>>u>>v;
        --u;--v;

        adj[u].push_back({v,i});
    }

    F(i,0,n-1)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }

    cout<<(cyclic ? 2 : 1);
    cout<<"\n";
    F(i,0,m-1)cout<<result[i]<<" ";
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
//	parsed : 08-July-2021 15:59:45 IST