//https://codeforces.com/contest/1497/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 17-March-2021 20:10:55 IST
*/

#include <bits/stdc++.h>
using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define dbg(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
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

void solve_LOL()
{
    int n, m;
    cin >> n >> m;

    int a[n];
    int cnt[mxn] = {};
    F(i, 0, n - 1)
    {
        cin >> a[i];
        cnt[a[i] % m]++;
    }

    set<int> s;
    
    if (cnt[0])
    {
        s.insert(0);
    }

    int z1 = 0;
    F(i, 1, m - 1)
    {
        // if(m-i<i)break;
        if (cnt[i] + cnt[m - i] == 1)
        {
            s.insert(min(i,m-i));
            // dbg(i,i);
            // dbg(i,s);
        }
        else if (cnt[i] + cnt[m - i] >= 2)
        {
            if (i == m - i || abs(cnt[i] - cnt[m - i])<=1)
            {
                s.insert(min(i,m-i));
                // dbg(i,s);
                // dbg(min(i,m-i),min(i,m-i),min(i,m-i));
            }
            else
            {
                s.insert(min(i,m-i));
                // dbg(i,s);

                // dbg(min(i,m-i),min(i,m-i),min(i,m-i),min(i,m-i));


                int mnn=min(cnt[i],cnt[m-i]);
                int mxx=max(cnt[i],cnt[m-i]);

                z1 += mxx-(mnn+1);
                // dbg(z1);
            }
        }
    }

    // dbg(z1);

    cout << z1/2 + sz(s);
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
        solve_LOL();
    }
    return 0;
}