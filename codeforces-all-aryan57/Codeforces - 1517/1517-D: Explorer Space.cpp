//https://codeforces.com/contest/1517/problem/D

/*
    // blog used
    author : aryan57
    created : 23-April-2021 21:33:27 IST
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

bool is_inside(int x, int y, int n, int m)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void solve_LOG()
{
    int n, m, kk;
    cin >> n >> m >> kk;

    int h[n + 1][m] = {};

    F(i, 1, n)
    {
        F(j, 1, m - 1)
        {
            cin >> h[i][j];
        }
    }

    int v[n][m + 1] = {};

    F(i, 1, n - 1)
    {
        F(j, 1, m)
        {
            cin >> v[i][j];
        }
    }

    int t = kk / 2;

    int dp[n + 1][m + 1][t + 1] = {};

    F(tt, 1, t)
    {
        F(i, 1, n)
        {
            F(j, 1, m)
            {
                dp[i][j][tt] = INF;

                if (is_inside(i - 1, j, n, m))
                {
                    dp[i][j][tt] = min(dp[i][j][tt], dp[i - 1][j][tt - 1] + v[i - 1][j]);
                }
                if (is_inside(i, j + 1, n, m))
                {
                    dp[i][j][tt] = min(dp[i][j][tt], dp[i][j + 1][tt - 1] + h[i][j]);
                }
                if (is_inside(i + 1, j, n, m))
                {
                    dp[i][j][tt] = min(dp[i][j][tt], dp[i + 1][j][tt - 1] + v[i][j]);
                }
                if (is_inside(i, j - 1, n, m))
                {
                    dp[i][j][tt] = min(dp[i][j][tt], dp[i][j - 1][tt - 1] + h[i][j - 1]);
                }
            }
        }
    }

    F(i, 1, n)
    {
        F(j, 1, m)
        {
            if (kk % 2)
                cout << "-1 ";
            else
                cout << 2 * dp[i][j][kk / 2] << " ";
        }

        cout << "\n";
    }
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