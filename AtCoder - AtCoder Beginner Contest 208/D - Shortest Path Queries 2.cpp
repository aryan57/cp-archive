/*
	group : AtCoder - AtCoder Beginner Contest 208
	name : D - Shortest Path Queries 2.cpp
	srcPath : /home/aryan/Documents/cp/D_Shortest_Path_Queries_2.cpp
	url : https://atcoder.jp/contests/abc208/tasks/abc208_d
*/
/*
    author : aryan57
    created : 04-July-2021 18:00:48 IST
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
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

void solve_LOG()
{

    int n, m;
    cin >> n >> m;

    int d[n][n];
    fill_n(&d[0][0], n * n, INF);

    F(i, 0, m - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        d[u][v] = w;
    }

    F(i,0,n-1)
    {
        d[i][i]=0;
    }

    int ans = 0;

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(d[i][j]!=INF)ans+=d[i][j];
            }
        }
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
    int _t = 1;
    // cin>>_t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}
//	parsed : 04-July-2021 17:34:52 IST