/*
    // tut used...
    author : Aryan Agarwal, IIT KGP
    created : 21-December-2020 13:29:20 IST
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
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

vector<int> adj[mxn + 1];
vector<int> vis(mxn + 1);

void dfs(int u)
{
    vis[u] = 1;

    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    F(i, 1, m)
    {
        adj[i].clear();
        vis[i] = 0;
    }

    vector<int> r(n + 1), c(n + 1);

    vector<pair<int, int>> vec(m + 1);

    F(i, 1, m)
    {
        cin >> vec[i].X >> vec[i].Y;
        r[vec[i].X] = i;
        c[vec[i].Y] = i;
    }

    set<int> V;
    set<pair<int, pair <int,int> >> E;

    F(i, 1, n)
    {

        if (r[i] == c[i])
        {
            vis[r[i]] = 1;
            continue;
        }
        if (r[i] == 0 && c[i])
        {
            V.insert(c[i]);
            adj[c[i]].pb(c[i]);
            continue;
        }
        if (r[i] && c[i] == 0)
        {

            V.insert(r[i]);
            adj[r[i]].pb(r[i]);
            continue;
        }

        V.insert(r[i]);
        V.insert(c[i]);
        E.insert({i,{min(r[i], c[i]), max(r[i], c[i])}});
        adj[r[i]].pb(c[i]);
        adj[c[i]].pb(r[i]);
    }

    // dbg(sz(V),sz(E));

    int component = 0;

    F(i, 1, m)
    {
        if (!vis[i])
        {
            dfs(i);
            component++;
        }
    }

    int cycles = sz(E) - sz(V) + component;

    cout << sz(V) + cycles << "\n";
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
    int _t = 1;
    cin >> _t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}