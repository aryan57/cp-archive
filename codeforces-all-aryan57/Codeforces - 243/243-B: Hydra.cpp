//https://codeforces.com/contest/243/problem/B

/*
    author : aryan57
    created : 18-May-2021 08:20:17 IST
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

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);
vector <int> adj[mxn+1];

bool comp(pair <int,int>  a, pair <int,int>  b)
{
    return sz(adj[a.X])+sz(adj[a.Y]) > sz(adj[b.X])+sz(adj[b.Y]);
}

void solve_LOG()
{
    int n,m,h,t;
    cin>>n>>m>>h>>t;

    
    vector<pair<int,int> > edge;
    F(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        edge.push_back({u,v});
        edge.push_back({v,u});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    F(i,1,n)
    {
        sort(all(adj[i]));
    }

    // dbg(adj[1],adj[4]);

    sort(all(edge),comp);

    for(auto p : edge)
    {
        int u=p.X;
        int v=p.Y;
        if(sz(adj[u])<h || sz(adj[v])<t)continue;

        vector<int> hh;
        vector<int> tt;
        unordered_set<int> common;

        for(int to : adj[u])
        {
            if(to==v)continue;
            
            if(sz(hh)>=h)break;

            if(adj[v].empty() || !binary_search(all(adj[v]),to))
            {
                hh.push_back(to);
            }
            else
            {
                if(sz(common)>=t+h-sz(hh))
                {
                    break;
                }
                else
                {
                    common.insert(to);
                }
            }

        }
        for(int to : adj[v])
        {
            if(to==u)continue;

            if(sz(tt)>=t)break;

            if(adj[u].empty() || !binary_search(all(adj[u]),to))
            {
                tt.push_back(to);
            }
            else
            {
                if(sz(common)>=t-sz(tt)+h-sz(hh))
                {
                    break;
                }
                else
                {
                    common.insert(to);
                }
            }

        }

        for(int x : common)
        {
            if(sz(hh)<h)
            {
                hh.push_back(x);
                continue;
            }
            if(sz(tt)<t)
            {
                tt.push_back(x);
                continue;
            }
            break;
        }

        if(sz(hh)==h && sz(tt)==t)
        {
            cout<<"YES\n";
            cout<<u<<" "<<v<<"\n";
            for(int x : hh)cout<<x<<" ";
            cout<<"\n";
            for(int x : tt)cout<<x<<" ";
            cout<<"\n";
            return;
        }
        
    }

    cout<<"NO\n";


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