//https://codeforces.com/contest/1214/problem/D

/*
    // tut used...
    author : Aryan Agarwal, IIT KGP
    created : 23-December-2020 22:51:23 IST
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

int n, m;
void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &graph, int op)
{
    visited[x][y] = true;

    if (x + op >= 1 && x + op <= n && graph[x + op][y] && !visited[x+op][y])
        dfs(x + op, y, visited, graph, op);
    if (y + op >= 1 && y + op <= m && graph[x][y + op] && !visited[x][y+op])
        dfs(x, y + op, visited, graph, op);
}

void solve_LOG()
{

    cin >> n >> m;

    vector<vector<int>> gr(n + 1, vector<int>(m + 1, 1));

    F(i, 1, n)
    {
        F(j, 1, m)
        {
            char c;
            cin >> c;
            if (c == '#')
                gr[i][j] = 0;
        }
    }

    vector<vector<bool>> vs(n + 1, vector<bool>(m + 1, false));
    vector<vector<bool>> vt(n + 1, vector<bool>(m + 1, false));

    dfs(1, 1, vs, gr, 1);

    if (!vs[n][m])
    {
        cout << 0;
        return;
    }

    dfs(n, m, vt, gr, -1);

    int cnt[n+m+1]={};

    F(i,1,n)
    {
        F(j,1,m)
        {
            if(vs[i][j] && vt[i][j])cnt[i+j]++;
        }
    }

    F(i,3,n+m-1)
    {
        if(cnt[i]==1)
        {
            cout<<1;
            return;
        }
    }

    cout << 2;
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
    // cin>>_t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}