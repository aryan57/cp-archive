/*
	group : AtCoder - AtCoder Beginner Contest 204
	name : E - Rush Hour 2.cpp
	srcPath : /home/aryan/Documents/cp/E_Rush_Hour_2.cpp
	url : https://atcoder.jp/contests/ABC204/tasks/abc204_e
*/
/*
    author : aryan57
    created : 06-June-2021 18:04:35 IST
*/
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
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
const long long INF = 1e16;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

struct Edge
{
    int u, v, d, c;
};


void solve_LOG()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> adj[n + 1];

    F(i, 1, m)
    {
        Edge e;
        cin >> e.u >> e.v >> e.c >> e.d;
        // if(e.u==e.v)continue;
        adj[e.u].push_back(e);
        adj[e.v].push_back(e);
    }

    vector<int> mn(n + 1, INF);

    mn[1] = 0;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        int v = q.top().second;
        int mn_v = q.top().first;
        q.pop();
        if (mn_v != mn[v])
            continue;

        for (auto edge : adj[v])
        {
            int c=edge.c;
            int d=edge.d;

            int to=-1;
            if(edge.u==v)to=edge.v;
            else to=edge.u;

            int temp=INF;

            int dd=(int)sqrt(d);

            F(t,max(0ll,dd-(mn[v]+1)-5),max(0ll,dd-(mn[v]+1)+5))
            {
                temp=min(temp,mn[v]+t+c+d/(mn[v]+t+1));
            }

            if (temp < mn[to])
            {
                mn[to] = temp;
                q.push({mn[to], to});
            }
        }
    }

    if (mn[n] == INF)
    {
        cout << "-1\n";
        return;
    }

    cout << mn[n];
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
    int _t = 1;
    // cin>>_t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}
//	parsed : 06-June-2021 18:04:32 IST