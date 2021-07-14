//https://codeforces.com/contest/1504/problem/E

/*
    // tut used...
    author : Aryan Agarwal, IIT Kharagpur
    created : 03-April-2021 22:54:05 IST
*/

#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
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

void solve_LOG()
{
    int n;
    cin>>n;

    int ss=0;

    vector<pair<pair <int,int> ,int> > v(n);

    F(i,0,n-1)
    {
        cin>>v[i].X.X>>v[i].X.Y;
        v[i].Y=i;

        ss+=v[i].X.Y;
    }

    sort(all(v));

    vector <pair <int,int> > adj[n];

    F(i,0,n-1)
    {
        int a1=v[i].X.X;
        int c1=v[i].X.Y;
        int ind=v[i].Y;

        if(i)
        {
            adj[ind].pb({v[i-1].Y,0});
        }

        auto p = make_pair(make_pair(a1+c1,INF),INF);
        int j=upper_bound(all(v),p)-v.begin();


        if(j<n && j!=i)
        {
            int a2=v[j].X.X;
            int c2=v[j].X.Y;
            int ind2=v[j].Y;

            adj[ind].pb({ind2,max(0ll,a2-a1-c1)});
        }

        j--;

        if(j>=0 && j!=i)
        {
            int a2=v[j].X.X;
            int c2=v[j].X.Y;
            int ind2=v[j].Y;

            adj[ind].pb({ind2,0});
        }
    }

    // O(nlogn+mlogn)
    // Dijkstra on sparse graphs

    vector <int> d(n,INF);
    vector <int> par(n,-1);
    int source=v[0].Y;
    d[source] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, source});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                /*
                    q.erase({d[to], to});

                    no need to erase, let the old pair be in the priority_queue,
                    since we are always accessing the smallest pair,
                    this old pair will never be used.
                */
                d[to] = d[v] + len;
                q.push({d[to], to});
                par[to]=v;
            }
        }
    }


    cout<<d[v[n-1].Y]+ss;
    
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}