/*
	group : Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
	name : E. Permutation Shift.cpp
	srcPath : /home/aryan/Documents/cp/E_Permutation_Shift.cpp
	url : https://codeforces.com/contest/1553/problem/E
*/
/*
    author : aryan57
    created : 22-July-2021 21:54:30 IST
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

// returns true if array p can be converted into array a by atmost m swaps
bool f(vector<int> &p, vector<int> &a, int m)
{
    int n = sz(p);
    vector<vector<int>> adj(n);
    vector<int> pos(n);

    F(i, 0, n - 1)
    {
        pos[a[i]] = i;
    }

    F(i, 0, n - 1)
    {
        adj[i].push_back(pos[p[i]]);
    }

    int cycles = 0;
    vector<bool> vis(n, false);

    F(i, 0, n - 1)
    {
        if (!vis[i])
        {
            cycles++;
            int cur = i;

            while (!vis[cur])
            {
                vis[cur] = true;
                cur = adj[cur][0];
            }
        }
    }

    return n - cycles <= m;
}

void solve_LOL()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    vector<int> cnt(n);

    F(i, 0, n - 1)
    {
        cin >> a[i];
        --a[i];

        int k = (n + i - a[i]) % n;
        cnt[k]++;
    }
    vector<int> ans;
    F(k, 0, n - 1)
    {
        /*
            atleast n/3 characters must match
            so that the remaining 2n/3 characters can be matched in atmost n/3 swaps
        */

        if (cnt[k] >= n - 2*m)
        {
            vector<int> p(n);
            iota(all(p), 0);
            if (k)
                rotate(p.begin(), p.begin() + n - k, p.end()); // [....n,1,2,...]

            if (f(p, a, m))
            {
                ans.push_back(k);
            }
        }
    }

    cout << sz(ans) << " ";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
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
    cin >> _t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 22-July-2021 21:21:03 IST