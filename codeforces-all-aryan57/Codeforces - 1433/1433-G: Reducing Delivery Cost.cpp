//https://codeforces.com/contest/1433/problem/G

/*
    author : aryan57
    created : 20-April-2021 20:22:19 IST
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

// #define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const int INF = 1e9;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

void solve_LOG()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<pair<int,int> > adj[n];
    vector<pair<pair <int,int> ,int> > edge(m);
    F(i,0,m-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edge[i]={{u,v},w};
    }

    vector< vector<int> > d(n,vector <int> (n,INF));
    vector< vector<int> > p(n,vector <int> (n,-1));

    F(s,0,n-1)
    {
    
        d[s][s] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (d_v != d[s][v])
                continue;
    
            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;
    
                if (d[s][v] + len < d[s][to]) {
                    d[s][to] = d[s][v] + len;
                    p[s][to] = v;
                    q.push({d[s][to], to});
                }
            }
        }
    }

    vector<pair<int,int> > vec(k);

    F(i,0,k-1)
    {
        int s,t;
        cin>>s>>t;
        --s;--t;
        vec[i]={s,t};
    }

    int ans=INF;

    F(i,0,m-1)
    {
        int u=edge[i].X.X;
        int v=edge[i].X.Y;

        int tot=0;
        F(j,0,k-1)
        {
            int source=vec[j].X;
            int sink=vec[j].Y;

            int d1=d[source][sink];
            int d2=d[source][v]+d[sink][u];
            int d3=d[source][u]+d[sink][v];

            tot+=min({d1,d2,d3});
        }

        ans=min(ans,tot);
    }

    cout<<ans;
    
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